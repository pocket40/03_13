//���� ����� Ȱ�� 1. ���¸� ������ �ʰ� ���� �ִ� �Լ��� �ϳ��� ��� ����� ���
#include <iostream>
using namespace std;

class Calc
{
private:
	Calc(); // �⺻ �����ڸ� private������ ����

public:
	static const double PI; //PI == 3.14
	
	static int square(int x) {
		return x * x;
	}

	static double getCircleArea(int radius) {
		return radius * radius * PI;
	}
};
const double Calc::PI = 3.14;

int main() {
	cout << Calc::square(2) << endl;
	cout << Calc::getCircleArea(2) << endl;

	return 0;
}