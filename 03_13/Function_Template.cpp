//함수 템플릿은 타입에 따른 함수를 자동으로 생성하는 기능을 의미

#include <iostream>
using namespace std;

template<typename T> T Max(T a, T b) { return a > b ? a : b; }

int main() {
	cout << Max(2, 1) << endl;
	cout << Max(1.1, 2.2) << endl;

	return 0;
}