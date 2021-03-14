#include <iostream>
using namespace std;

// 정적 멤버 함수(Static Memver Function)
//static 키워드를 사용하여 선언된 멤버 함수를 의미
//정적 멤버 함수는 객체의 생성없이 호출되는 함수로 일반적인 전역 함수와 동일한 개념임
//객체의 주소가 없으므로 일반 멤버는 접근할 수 없음
class Clazz
{
	int val;

public:
	void func() { // vvoid func(Clazz* const this);
		val = 0; // OK, this->val();
		func(); // OK, this->func();
		sFunc(); // OK, sFunc();
	}

	static void sFunc() { // void sFunc(); // 정적 멤버 함수
		cout << "Clazz:sFunc()" << endl;

		//val = 0;	//ERROR, this->val = 0;
		//func(); //
		sFunc(); 
	}
};

int main() {
	Clazz::sFunc(); // cout << "Clazz:sFunc()" << endl; static이면 접근 가능
	//Clazz::func(); // ERROR

	Clazz obj; // static 이 없으니가 레퍼런스 생성해서 접근
	obj.func();
	return 0;
}