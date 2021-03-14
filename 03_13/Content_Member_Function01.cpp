//상수 멤버 함수를 사용하는 이유 상수 객체만이 상수 함수를 사용할 수 있음
#include <iostream>
using namespace std;

class Int32 
{
	int val;

public:
	Int32(int v= 0): val(v) {}

	void setValue(int val) {
		this->val = val;
	}

	void display() const {
		cout << val << endl;
	}
};

void printInt32(const Int32& i32) {
	//i32.setValue(10); //ERROR
	i32.display();
}

int main() {
	Int32 i32;
	printInt32(i32);

	return 0;
}