//정적 멤버의 활용 1. 상태를 가지지 않고 관련 있는 함수를 하나로 묶어서 사용할 경우
#include <iostream>
using namespace std;

class Calc
{
private:
	Calc(); // 기본 생성자를 private영역에 선언

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