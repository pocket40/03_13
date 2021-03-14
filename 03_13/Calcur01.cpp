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

/*���ø� ���� ����*/
template<typename T> 
class Stack {
private:
	T* arr;			//�������
	int top;		// ���� ������
	int size;		//���� ũ��
public:
	Stack() : arr(0), top(0), size(30) {		//�⺻ ������ (ũ��, top��, ũ�⿡�´� ���� ����)
		arr = new T[size];
		size = size;
		top = 0;
	}
	~Stack() { delete[] arr; }

	bool isFull() { return (top == size); }
	bool isEmpty() { return (top == 0); }

	void push(const T& data) { arr[top++] = data; }		//������ ����
	T& top_val() { return arr[top - 1]; }					//top �� ��ȯ
	T& pop() { return arr[--top]; }						//������ ���
};

Stack<precedence> trans;		//���� ��ȯ�� ����� ����, enum���� �־��� ���̹Ƿ� precedence����
Stack<double> cal;				//���� ��ȯ �� ��� �� ����� �����̹Ƿ� double�� ����
string s;						// �Է¹��� ���ڿ� �������
char t[50];						//���� ��ȯ �� ������� (atof�Լ��� ����ϱ� ���� char�迭�� ����) 
int icp[] = { 20,19,12,12,13,13,0,0,20 };	//���ÿ� ���� �켱����
int isp[] = { 0,19,12,12,13,13,0,0,20 };	//���þȿ� ���� �� �켱����
int tlen;		//�����ڸ��� ���� ������ ���� ������ȯ���� ���� ���̿� \0���� �־��־��� ������ ���̰� 
				//�������̾ t�� ���̸� �����ϴ� ���� ���� ����

/*
�Է¹��� ���ڿ��� enum�����͸� �޾ƿ��� �Լ�, Ư���� -�� ������ȣ�� ������ ������ ���� NEGATIVE���
�����ڸ� �ϳ� �� �߰��ؼ� �������־���.
*/
precedence get_token(char* symbol, int* n) {
	int tmp = 0;
	*symbol = s[(*n)++];	//�ɺ��� ���� ������ �ε��� ����

	switch (*symbol) {			//�ɺ��� ���� �ش��ϴ� enum������ ��ȯ�ϵ��� ����
	case '-':
		if (*n == 1) return NEGATIVE;		//��ó�� - �� ������ ������ȣ
		else if ((s[(*n) - 2] >= '0' && s[(*n) - 2] <= '9') || (s[(*n) - 2] == ')')) return MINUS; //-�տ� �ǿ����� Ȥ�� )�� ������ ���� �����ڷ� ���̱� ������ �̶��� MINUS��ȯ
		else return NEGATIVE;		//�� �ܴ� ��� ���� ��ȣ ���
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
����->������ȯ �Լ�
*/
void postfix(void) {
	char symbol;		//�Է¹��� �迭�� ���ڸ� token���� ��ȯ �� �����ϱ����� char�� ����
	precedence token;
	int n = 0;			//�Է¹��� �迭s�� �ε��������� ����
	int j = 0;			//���� ��ȯ�� ������ t�迭�� �ε��������� ����

	trans.push(EOS);	//���� ó���� EOS�߰�

	//token�� enum���� �޾ƿͼ� �����ڿ� ��ȣ, �ǿ����ڸ� ������ �ش��ϴ� ����� �����ϵ��� �ݺ��� ����
	//get_token�Լ��� ���� �Է¹��� �迭 s�� �ε����� �������Ѱ��� ������ȯ�� 
	for (token = get_token(&symbol, &n); token != EOS; token = get_token(&symbol, &n)) {
		if (token == OPERAND) {		//�������� ���
			t[j++] = symbol;		//���ڸ� �������·� ���� '0'~'9' = ������ 48~57
		}
		else if (token == RPAREN) {	//������ ��ȣ�� ���
			while (trans.top_val() != LPAREN) {	//���� ��ȣ ���ö����� 
				t[j++] = trans.pop();			//������ ������ t�� ����
			}
			trans.pop();	//�°�ȣ ������ 
		}
		else {						//������ �� �°�ȣ�� ���
			if (j != 0) {			//���ڸ� ���� ������ �ֱ� ���� ���� ���̿� \0���� �־���
				if (t[j - 1] >= '0' && t[j - 1] <= '9') {
					t[j++] = '\0';
				}
			}

			while (isp[trans.top_val()] > icp[token]) {	//�� �������� �켱������ �� ���ٸ�
				t[j++] = trans.pop();					//�ڽź��� �켱������ ���� �����ڰ� ���ö����� pop

			}
			trans.push(token);							//�Ŀ� ���ÿ� ����.
		}

	}
	//�Է¹迭�� ��� ���� ���� �� ���ÿ� �����ִ� �����ڵ��� ���ʴ�� ��� �����ش�.
	while (trans.top_val() != EOS) {
		t[j++] = trans.pop();
	}

	t[j] = '\0';
	tlen = j;				//t�迭�� ���̸� ����
}

void calc() {


	char temp[30] = { 0, };		//t�迭�� ���ڹ��ڸ� ���ڷ� ��ȯ�ϱ� ���� �ӽ� �����ϴ� �迭
	char* arr = temp;				//atof�Լ��� ����ϱ����� temp�� �ٶ󺸴� ������ ����
	int tcnt = 0;				//temp�� �� ���ڹ��ڸ� ī��Ʈ�ϴ� ����	
	double t1, t2, t3;			//����� �ӽ� �����ϴ� ����
	double num;					//���ڹ��ڸ� double�� ���ڷ� ��ȯ�Ͽ� �����ϱ� ���� ����->�Ŀ� �� ���� ���ÿ� Ǫ������
	for (int i = 0; i < tlen; i++) {  //t�迭�� ��ȸ
		if (t[i] == '\0') {			//\0���� ������ ���� �ϳ��� �������̹Ƿ� �̸� �Ǽ�ȭ�Ͽ� ���ÿ� Ǫ���Ѵ�.
			temp[tcnt] = '\0';	//���ڿ��� ���ڷ� �ٲٱ����� ����
			num = atof(arr);		//����� ���ڸ� �Ǽ�ȭ
			cal.push(num);		//���ÿ� ���� ����
			for (int k = tcnt - 1; k >= 0; k--) {	//temp�� �����ִ� ������ ������� ���� ���ڵ� ��Ȯ�� ������ �� �ִ�.
				temp[k] = '\0';				//����� Ŀ�� �� �ִ� �κ������� �ϴ� ������ ���� �����ϰ� �������. (�� ���� ��� �����غ���) 
			}
			tcnt = 0;				//tcnt���� 0���� �ʱ�ȭ���༭ ���� ���ڰ� ó������ �Էµ� �� �ֵ��� �Ѵ�.
			continue;
		}
		if ((t[i] >= '0' && t[i] <= '9') || t[i] == '.') {	//����Ȥ�� . �̶�� temp�迭�� �����Ѵ�.
			temp[tcnt++] = t[i];
		}
		else {								//���ڰ� �ƴ϶��
			/*�̺κ��� ���� ��ȯ �Լ����� ����,������ ���� �������� \0���� �־��ִ� ������ ������ ���ؼ� �ӽ� ��������
			�ذ��ϱ� ���� �־��� if���̴�. �� �κе� �ϴ� ������ ���� ��������� �� ���ǹ� ���� �� �� ����ϰ� © �� ������ �����غ���.
			*/
			if (tcnt != 0) {		// ���ڸ� �����ؼ� ���ÿ� Ǫ�����ִ� ����
				temp[tcnt] = '\0';	//���ڿ��� ���ڷ� �ٲٱ����� ����
				num = atof(arr);		//����� ���ڸ� �Ǽ�ȭ
				cal.push(num);		//���ÿ� ���� ����
				for (int k = tcnt - 1; k >= 0; k--) {
					temp[k] = '\0';
				}
				tcnt = 0;
			}
			// �ǿ����� �ΰ� ������ ��� �� Ǫ��
			if (t[i] == PLUS) {
				t2 = cal.pop();
				t1 = cal.pop();
				t3 = t1 + t2;
				cal.push(t3);
			}
			else if (t[i] == MINUS) {// �ǿ����� �ΰ� ������ ��� �� Ǫ��
				t2 = cal.pop();
				t1 = cal.pop();
				t3 = t1 - t2;
				cal.push(t3);
			}
			else if (t[i] == TIME) {// �ǿ����� �ΰ� ������ ��� �� Ǫ��
				t2 = cal.pop();
				t1 = cal.pop();
				t3 = t1 * t2;
				cal.push(t3);
			}
			else if (t[i] == DIVIDE) {// �ǿ����� �ΰ� ������ ��� �� Ǫ��
				t2 = cal.pop();
				t1 = cal.pop();
				t3 = t1 / t2;
				cal.push(t3);
			}
			else if (t[i] == NEGATIVE) {// �ǿ����� �ϳ� ������ ���� �ٿ����� Ǫ��
				t1 = cal.pop();
				t1 = -t1;
				cal.push(t1);
			}
		}

	}
	//����� ��� 
	printf("%.3lf\n", cal.pop());

	return;
}


int main() {

	cin >> s;			//������ �Է�
	postfix();			//���� ��ȯ�Լ�
	calc();				//���� ��� �Լ�


	return 0;
}