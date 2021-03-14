#include <iostream>
#include <string>

using namespace std;

template <class T1, class T2>
void printAll(T1 a, T2 b) {
	cout << "t1 : " << a << endl;
	cout << "T2 : " << b << endl;
};

int main(void) {
	string s1 = "Dok2";
	string s2 = "On my way.";

	int num1 = 27;
	int num2 = 35;

	double d1 = 3.14;
	double d2 = 36.5;

	cout << "[string, string]" << endl;
	printAll(s1, s2);

	cout << "[string, int]" << endl;
	printAll(s1, num1);

	cout << "[int, double]" << endl;
	printAll(num1, num2);

	cout << "[double, double]" << endl;
	printAll(d1, d2);

	cout << "double,string]" << endl;
	printAll(d1, s1);

	return 0;
}