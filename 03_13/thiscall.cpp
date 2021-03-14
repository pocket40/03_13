#include<iostream>
using namespace std;

// 자기 자신을 가리키는 포인터 상수를 의미
class Int32 {
	int _val;

public:
	void setValue(int val) {
		this->_val = val;
	}
};

int main() {
	Int32 i32;
	i32.setValue(10);

	return 0;
}