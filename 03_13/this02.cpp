#include <iostream>
using namespace std;

class Car
{
public:
	Car* go() {
		cout << "go" << endl;
		return this;
		// this�� ����ϴ� ���� - ��� �Լ��� �������� ȣ�� ����
	}
};

int main()
{
	Car car;

	car.go()->go()->go();

	return 0;
}