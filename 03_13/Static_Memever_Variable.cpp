// static Ű���带 ����Ͽ� ����� ��� ������ �ǹ�
//���� ��� ������ ��ü�� �������� ������ �� �ִ� ������ �Ϲ����� ���� ������ ������ ������
//Ŭ���� ���ο� ���� ��� ������ �����̹Ƿ� �ݵ�� �ܺο� ���Ǹ� �ؾ� ��

#include<iostream>
using namespace std;

class Clazz
{
public:
	static int sVal; // ���� ��� ����

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