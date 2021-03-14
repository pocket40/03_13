#include <iostream>
using namespace std;

class Car
{
public:
	Car* go() {
		cout << "go" << endl;
		return this;
		// this를 사용하는 이유 - 멤버 함수를 연속으로 호출 가능
	}
};

int main()
{
	Car car;

	car.go()->go()->go();

	return 0;
}