//정적 멤버 함수는 C 언어의 함수 호출 방식과 동일하므로 일반 함수 일반 함수 포인터에 의해 처리될 수 있음
//그러나 일반 멤버 함수는 thiscall 방식이므로 일반 함수 포인터에 의해 처리될 수 없음
//thiscall 방식의 함수 포인터 선언 방법 - 리턴타입(클래스명::*변수명)([매개변수,...]);
//함수 포인터를 사용한 일반 멤버 함수 호출 방법 -.* 또는 ->* 연산자 사용

#include<iostream>
using namespace std;

void func() { cout << ":func()" << endl; }

class Clazz
{
public:
	void func() { cout << "Clazz:func()" << endl; }
	static void sFunc() { cout << "Clazz::sFunc()" << endl; }
};

int main() {
	//전역 함수
	void(*fp1)() = func;
	fp1(); // ok 

	// 정적 멤버 함수
	void(*fp2)() = &Clazz::sFunc;
	fp2(); // ok

	// 일반 멤버 함수
	//void(*fp3)() = &Clazz::func;//ERROR
	void(Clazz:: * fp3)() = &Clazz::func;
	//fp3(); //ERROR

	Clazz obj;
	(obj.*fp3)(); //ok

	Clazz* pObj = new Clazz();
	(pObj->*fp3)(); //ok, ->*: 포인터인 경우

	delete pObj;
	return 0;
}