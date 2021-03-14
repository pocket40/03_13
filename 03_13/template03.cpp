#include <iostream>
using namespace std;

// 함수 템플릿은 내부 연결성을 가지므로 반드시 템플릿 함수가 사용된 파일 안에 함수 템플릿이 완벽하게 정의되어 있어야 함

template<typename T> T Max(T a, T b) {
	return a > b ? a : b; // a = 1, b = 2 == 2
}

int main() {
	cout << Max(1, 2) << endl;
	return 0;
}