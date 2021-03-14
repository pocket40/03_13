//���� ��� �Լ��� C ����� �Լ� ȣ�� ��İ� �����ϹǷ� �Ϲ� �Լ� �Ϲ� �Լ� �����Ϳ� ���� ó���� �� ����
//�׷��� �Ϲ� ��� �Լ��� thiscall ����̹Ƿ� �Ϲ� �Լ� �����Ϳ� ���� ó���� �� ����
//thiscall ����� �Լ� ������ ���� ��� - ����Ÿ��(Ŭ������::*������)([�Ű�����,...]);
//�Լ� �����͸� ����� �Ϲ� ��� �Լ� ȣ�� ��� -.* �Ǵ� ->* ������ ���

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
	//���� �Լ�
	void(*fp1)() = func;
	fp1(); // ok 

	// ���� ��� �Լ�
	void(*fp2)() = &Clazz::sFunc;
	fp2(); // ok

	// �Ϲ� ��� �Լ�
	//void(*fp3)() = &Clazz::func;//ERROR
	void(Clazz:: * fp3)() = &Clazz::func;
	//fp3(); //ERROR

	Clazz obj;
	(obj.*fp3)(); //ok

	Clazz* pObj = new Clazz();
	(pObj->*fp3)(); //ok, ->*: �������� ���

	delete pObj;
	return 0;
}