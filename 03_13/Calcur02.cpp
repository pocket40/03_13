#include<iostream>

typedef enum {
	lparen,
	rparen,
	plus, // 더하기
	minus, //빼기
	divide, // 나누기
	times, // 곱하기
	eos, 
	operand,
	negative,
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

Stack<precedence> trans;		
Stack<double> cal;				
std::string s;					
char t[50];						
int icp[] = { 20,19,12,12,13,13,0,0,20 }; //우선 순위를 정해준다
int isp[] = { 0,19,12,12,13,13,0,0,20 };
int tlen;		 

precedence get_token(char* symbol, int* n) {
	int tmp = 0;
	*symbol = s[(*n)++];	

		switch (*symbol) {		
		case '-':
			if (*n == 1) return negative;		
			else if ((s[(*n) - 2] >= '0' && s[(*n) - 2] <= '9') || (s[(*n) - 2] == ')')) return minus; 
			else return negative;
		case '+': return plus;
		case '(': return lparen;
		case '*': return times;
		case '/': return divide;
		case ')': return rparen;
		case '\0': return eos;

		default: return operand;

		}
}

void postfix(void) {
	char symbol;		
	precedence token;
	int n = 0;			
	int j = 0;			

	trans.push(eos);	

	
	
	for (token = get_token(&symbol, &n); token != eos; token = get_token(&symbol, &n)) {
		if (token == operand) {		
			t[j++] = symbol;		
		}
		else if (token == rparen) {	
			while (trans.top_val() != lparen) {	
				t[j++] = trans.pop();			
			}
			trans.pop();	
		}
		else {				
			if (j != 0) {	
				if (t[j - 1] >= '0' && t[j - 1] <= '9') {
					t[j++] = '\0';
				}
			}

			while (isp[trans.top_val()] > icp[token]) {	
				t[j++] = trans.pop();					

			}
			trans.push(token);							
		}

	}
	
	while (trans.top_val() != eos) {
		t[j++] = trans.pop();
	}

	t[j] = '\0';
	tlen = j;				
}

void calc() {


	char temp[30] = { 0, };		
	char* arr = temp;			
	int tcnt = 0;				
	double t1, t2, t3;			
	double num;					
		for (int i = 0; i < tlen; i++) { 
			if (t[i] == '\0') {			
				temp[tcnt] = '\0';	
				num = atof(arr);	
				cal.push(num);		
				for (int k = tcnt - 1; k >= 0; k--) {	
					temp[k] = '\0';				
				}
				tcnt = 0;				
				continue;
			}
			if ((t[i] >= '0' && t[i] <= '9') || t[i] == '.') {	
				temp[tcnt++] = t[i];
			}
			else {
			
				if (tcnt != 0) {		
					temp[tcnt] = '\0';	
					num = atof(arr);	
					cal.push(num);		
					for (int k = tcnt - 1; k >= 0; k--) {
						temp[k] = '\0';
					}
					tcnt = 0;
				}
			
				if (t[i] == plus) {
					t2 = cal.pop();
					t1 = cal.pop();
					t3 = t1 + t2;
					cal.push(t3);
				}
				else if (t[i] == minus) {
					t2 = cal.pop();
					t1 = cal.pop();
					t3 = t1 - t2;
					cal.push(t3);
				}
				else if (t[i] == times) {
					t2 = cal.pop();
					t1 = cal.pop();
					t3 = t1 * t2;
					cal.push(t3);
				}
				else if (t[i] == divide) {
					t2 = cal.pop();
					t1 = cal.pop();
					t3 = t1 / t2;
					cal.push(t3);
				}
				else if (t[i] == negative) {
					t1 = cal.pop();
					t1 = -t1;
					cal.push(t1);
				}
			}

		}

	printf("%.3lf\n", cal.pop());

	return;
}

int main() {
	std::cin >> s;		
	postfix();			
	calc();				

	return 0;
}