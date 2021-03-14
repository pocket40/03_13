#include<iostream>
using namespace std;

void foo(int& value)
{
	value = 6;
}

int main()
{
	int value = 5;

	cout << "value=" << value << '\n'; // 지역변수 value=5출력
	foo(value); // value의 주소를 foo()함수에 대입
	cout << "value=" << value << '\n';
	return 0;
}