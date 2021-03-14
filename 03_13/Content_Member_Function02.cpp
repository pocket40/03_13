//��� ������ mutable�� �����ϸ� ��� ��� �Լ� �������� ���� ������ ����

#include <iostream>
using namespace std;

class Point
{
	int _x, _y;
	mutable char str[64]; // ��� ��� �Լ� �������� ���� ������ ����

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