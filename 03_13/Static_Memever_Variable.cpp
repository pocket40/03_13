// static 키워드를 사용하여 선언된 멤버 변수를 의미
//정적 멤버 변수는 객체의 생성없이 접근할 수 있는 변수로 일반적인 전역 변수와 동일한 개념임
//클래스 내부에 정적 멤버 변수는 선언이므로 반드시 외부에 정의를 해야 함

#include<iostream>
using namespace std;

class Clazz
{
public:
	static int sVal; // 정적 멤버 변수

	void func() {
		sVal = 0;  // ok sVal = 0;
	}

	static void sfunc() { //ok sVal = 0;
		sVal = 0; 
	}
};
int Clazz::sVal;

int main() {
	cout << Clazz::sVal << endl;
	return 0;
}