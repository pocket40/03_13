#include<iostream>
using namespace std;

void foo(int& value)
{
	value = 6;
}

int main()
{
	int value = 5;

	cout << "value=" << value << '\n'; // �������� value=5���
	foo(value); // value�� �ּҸ� foo()�Լ��� ����
	cout << "value=" << value << '\n';
	return 0;
}