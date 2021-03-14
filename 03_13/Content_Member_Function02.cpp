//멤버 변수를 mutable로 선언하면 상수 멤버 함수 내에서도 값의 수정이 가능

#include <iostream>
using namespace std;

class Point
{
	int _x, _y;
	mutable char str[64]; // 상수 멤버 함수 내에서도 값의 수정이 가능

public:
	Point(int x, int y) : _x(x), _y(y) {}

	char* to_str() const {
		sprintf(str, "=%d, y=%d", _x, _y);
		return str;
	}
};

int main() {
	Point p(1, 1);
	cout << p.to_str() << endl;

	return 0;
}