//임시 객체는 프로그램의 실행 도중에 잠시 잠깐 생성되었다 사라지는 객체를 의미
//임시 객체는 이름이 없기 때문에 이름 없는 객체라고도 함

#include <cstdio>
#include <iostream>
using namespace std;

class Int32
{
	int val;
public:
	Int32(int v = 0) : val(v) {
		cout << "Int32(" << v << ")" << endl;
	}

	~Int32() { cout << "~Int32()" << endl; }
};

int main() {
	Int32 i32(10); // 지역 객체, 이름 잇음
	Int32(20); // 임시 객체, 이름없음
	getchar();

	return 0;
}