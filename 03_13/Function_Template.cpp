//�Լ� ���ø��� Ÿ�Կ� ���� �Լ��� �ڵ����� �����ϴ� ����� �ǹ�

#include <iostream>
using namespace std;

template<typename T> T Max(T a, T b) { return a > b ? a : b; }

int main() {
	cout << Max(2, 1) << endl;
	cout << Max(1.1, 2.2) << endl;

	return 0;
}