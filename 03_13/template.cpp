//template(템플릿)
//함수나 클래스를 개별적으로 다시 작성하지 않아도,
//여러 자료 형으로 사용할 수 있도록 하게 만들어 놓은 틀

#include <iostream>
#include <string>

using namespace std;

template <typename T>
T sum(T a, T b) {
	return a + b; // a + b 값을 반환
}

int main(void) {
	int a = 1, b = 2;

	double d1 = 2.2;
	double d2 = 3.3;

	string s1 = "show me";
	string s2 = "The Money6";

	cout << "int합 : " << sum<int>(a, b) << endl;
	cout << "double합 : " << sum<double>(d1, d2) << endl;
	cout << "string합 : " << sum<string>(s1, s2) << endl;

	return 0;
}