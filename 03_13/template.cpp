//template(���ø�)
//�Լ��� Ŭ������ ���������� �ٽ� �ۼ����� �ʾƵ�,
//���� �ڷ� ������ ����� �� �ֵ��� �ϰ� ����� ���� Ʋ

#include <iostream>
#include <string>

using namespace std;

template <typename T>
T sum(T a, T b) {
	return a + b; // a + b ���� ��ȯ
}

int main(void) {
	int a = 1, b = 2;

	double d1 = 2.2;
	double d2 = 3.3;

	string s1 = "show me";
	string s2 = "The Money6";

	cout << "int�� : " << sum<int>(a, b) << endl;
	cout << "double�� : " << sum<double>(d1, d2) << endl;
	cout << "string�� : " << sum<string>(s1, s2) << endl;

	return 0;
}