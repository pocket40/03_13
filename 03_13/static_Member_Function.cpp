#include <iostream>
using namespace std;

// ���� ��� �Լ�(Static Memver Function)
//static Ű���带 ����Ͽ� ����� ��� �Լ��� �ǹ�
//���� ��� �Լ��� ��ü�� �������� ȣ��Ǵ� �Լ��� �Ϲ����� ���� �Լ��� ������ ������
//��ü�� �ּҰ� �����Ƿ� �Ϲ� ����� ������ �� ����
class Clazz
{
	int val;

public:
	void func() { // vvoid func(Clazz* const this);
		val = 0; // OK, this->val();
		func(); // OK, this->func();
		sFunc(); // OK, sFunc();
	}

	static void sFunc() { // void sFunc(); // ���� ��� �Լ�
		cout << "Clazz:sFunc()" << endl;

		//val = 0;	//ERROR, this->val = 0;
		//func(); //
		sFunc(); 
	}
};

int main() {
	Clazz::sFunc(); // cout << "Clazz:sFunc()" << endl; static�̸� ���� ����
	//Clazz::func(); // ERROR

	Clazz obj; // static �� �����ϰ� ���۷��� �����ؼ� ����
	obj.func();
	return 0;
}