#include<iostream>
#include<string>

using namespace std;

typedef enum {
	LPAREN,
	RPAREN,
	PLUS,
	MINUS,
	TIME,
	DIVIDE,
	EOS,
	OPERAND,
	NEGATIVE,

} precedence;

/*템플릿 스택 선언*/
template<typename T> 
class Stack {
private:
	T* arr;			//저장공간
	int top;		// 스택 포인터
	int size;		//스택 크기
public:
	Stack() : arr(0), top(0), size(30) {		//기본 생성자 (크기, top값, 크기에맞는 공간 생성)
		arr = new T[size];
		size = size;
		top = 0;
	}
	~Stack() { delete[] arr; }

	bool isFull() { return (top == size); }
	bool isEmpty() { return (top == 0); }

	void push(const T& data) { arr[top++] = data; }		//데이터 저장
	T& top_val() { return arr[top - 1]; }					//top 값 반환
	T& pop() { return arr[--top]; }						//데이터 출력
};

Stack<precedence> trans;		//후위 변환시 사용할 스택, enum으로 넣어줄 것이므로 precedence선언
Stack<double> cal;				//후위 변환 후 계산 시 사용할 스택이므로 double로 선언
string s;						// 입력받을 문자열 저장공간
char t[50];						//후위 변환 식 저장공간 (atof함수를 사용하기 위해 char배열로 받음) 
int icp[] = { 20,19,12,12,13,13,0,0,20 };	//스택에 들어갈때 우선순위
int isp[] = { 0,19,12,12,13,13,0,0,20 };	//스택안에 있을 때 우선순위
int tlen;		//여러자리수 숫자 구분을 위해 후위변환식의 숫자 사이에 \0값을 넣어주었기 때문에 길이가 
				//가변적이어서 t의 길이를 저장하는 변수 따로 선언

/*
입력받은 문자열의 enum데이터를 받아오는 함수, 특별히 -는 음수부호와 빼기의 구분을 위해 NEGATIVE라는
연산자를 하나 더 추가해서 구분해주었다.
*/
precedence get_token(char* symbol, int* n) {
	int tmp = 0;
	*symbol = s[(*n)++];	//심볼에 문자 저장후 인덱스 증가

	switch (*symbol) {			//심볼에 따라 해당하는 enum데이터 반환하도록 설계
	case '-':
		if (*n == 1) return NEGATIVE;		//맨처음 - 는 무조건 음수부호
		else if ((s[(*n) - 2] >= '0' && s[(*n) - 2] <= '9') || (s[(*n) - 2] == ')')) return MINUS; //-앞에 피연산자 혹은 )가 있으면 빼기 연산자로 쓰이기 때문에 이때는 MINUS반환
		else return NEGATIVE;		//그 외는 모두 음수 부호 취급
	case '+': return PLUS;
	case '(': return LPAREN;
	case '*': return TIME;
	case '/': return DIVIDE;
	case ')': return RPAREN;
	case '\0': return EOS;

	default: return OPERAND;


	}
}
/*
중위->후위변환 함수
*/
void postfix(void) {
	char symbol;		//입력받은 배열의 문자를 token으로 변환 시 참조하기위한 char형 변수
	precedence token;
	int n = 0;			//입력받은 배열s의 인덱스를위한 변수
	int j = 0;			//후위 변환을 저장할 t배열의 인덱스를위한 변수

	trans.push(EOS);	//스택 처음에 EOS추가

	//token에 enum값을 받아와서 연산자와 괄호, 피연산자를 구분해 해당하는 기능을 수행하도록 반복문 구성
	//get_token함수를 통해 입력받은 배열 s의 인덱스를 증가시켜가며 후위변환함 
	for (token = get_token(&symbol, &n); token != EOS; token = get_token(&symbol, &n)) {
		if (token == OPERAND) {		//연산자일 경우
			t[j++] = symbol;		//숫자를 문자형태로 저장 '0'~'9' = 정수값 48~57
		}
		else if (token == RPAREN) {	//오른쪽 괄호일 경우
			while (trans.top_val() != LPAREN) {	//왼쪽 괄호 나올때까지 
				t[j++] = trans.pop();			//연산자 꺼내서 t에 저장
			}
			trans.pop();	//좌괄호 버리기 
		}
		else {						//연산자 및 좌괄호일 경우
			if (j != 0) {			//두자리 수를 구분해 주기 위해 숫자 사이에 \0값을 넣어줌
				if (t[j - 1] >= '0' && t[j - 1] <= '9') {
					t[j++] = '\0';
				}
			}

			while (isp[trans.top_val()] > icp[token]) {	//들어갈 연산자의 우선순위가 더 낮다면
				t[j++] = trans.pop();					//자신보다 우선순위가 낮은 연산자가 나올때까지 pop

			}
			trans.push(token);							//후에 스택에 들어간다.
		}

	}
	//입력배열을 모두 돌고 나온 후 스택에 남아있는 연산자들을 차례대로 모두 꺼내준다.
	while (trans.top_val() != EOS) {
		t[j++] = trans.pop();
	}

	t[j] = '\0';
	tlen = j;				//t배열의 길이를 저장
}

void calc() {


	char temp[30] = { 0, };		//t배열의 숫자문자를 숫자로 변환하기 위해 임시 저장하는 배열
	char* arr = temp;				//atof함수를 사용하기위해 temp를 바라보는 포인터 선언
	int tcnt = 0;				//temp에 들어간 숫자문자를 카운트하는 변수	
	double t1, t2, t3;			//연산시 임시 저장하는 변수
	double num;					//숫자문자를 double형 숫자로 변환하여 저장하기 위한 변수->후에 이 값을 스택에 푸쉬해줌
	for (int i = 0; i < tlen; i++) {  //t배열을 순회
		if (t[i] == '\0') {			//\0값이 나오면 숫자 하나가 끝난것이므로 이를 실수화하여 스택에 푸쉬한다.
			temp[tcnt] = '\0';	//문자열을 숫자로 바꾸기위한 조작
			num = atof(arr);		//저장된 문자를 실수화
			cal.push(num);		//스택에 숫자 저장
			for (int k = tcnt - 1; k >= 0; k--) {	//temp에 남아있던 흔적을 지워줘야 다음 숫자도 정확히 구분할 수 있다.
				temp[k] = '\0';				//비용이 커질 수 있는 부분이지만 일단 구현을 위해 감수하고 만들었다. (더 좋은 방법 생각해보기) 
			}
			tcnt = 0;				//tcnt값을 0으로 초기화해줘서 다음 숫자가 처음부터 입력될 수 있도록 한다.
			continue;
		}
		if ((t[i] >= '0' && t[i] <= '9') || t[i] == '.') {	//숫자혹은 . 이라면 temp배열에 저장한다.
			temp[tcnt++] = t[i];
		}
		else {								//숫자가 아니라면
			/*이부분은 후위 변환 함수에서 숫자,연산자 구분 지점마다 \0값을 넣어주는 조작을 수행을 못해서 임시 방편으로
			해결하기 위해 넣어준 if문이다. 이 부분도 일단 구현을 위해 만들었지만 이 조건문 없이 좀 더 깔끔하게 짤 수 있으니 생각해보자.
			*/
			if (tcnt != 0) {		// 숫자를 구분해서 스택에 푸쉬해주는 조작
				temp[tcnt] = '\0';	//문자열을 숫자로 바꾸기위한 조작
				num = atof(arr);		//저장된 문자를 실수화
				cal.push(num);		//스택에 숫자 저장
				for (int k = tcnt - 1; k >= 0; k--) {
					temp[k] = '\0';
				}
				tcnt = 0;
			}
			// 피연산자 두개 꺼내서 계산 후 푸쉬
			if (t[i] == PLUS) {
				t2 = cal.pop();
				t1 = cal.pop();
				t3 = t1 + t2;
				cal.push(t3);
			}
			else if (t[i] == MINUS) {// 피연산자 두개 꺼내서 계산 후 푸쉬
				t2 = cal.pop();
				t1 = cal.pop();
				t3 = t1 - t2;
				cal.push(t3);
			}
			else if (t[i] == TIME) {// 피연산자 두개 꺼내서 계산 후 푸쉬
				t2 = cal.pop();
				t1 = cal.pop();
				t3 = t1 * t2;
				cal.push(t3);
			}
			else if (t[i] == DIVIDE) {// 피연산자 두개 꺼내서 계산 후 푸쉬
				t2 = cal.pop();
				t1 = cal.pop();
				t3 = t1 / t2;
				cal.push(t3);
			}
			else if (t[i] == NEGATIVE) {// 피연산자 하나 꺼내서 음수 붙여준후 푸쉬
				t1 = cal.pop();
				t1 = -t1;
				cal.push(t1);
			}
		}

	}
	//결과값 출력 
	printf("%.3lf\n", cal.pop());

	return;
}


int main() {

	cin >> s;			//중위식 입력
	postfix();			//후위 변환함수
	calc();				//후위 계산 함수


	return 0;
}