#include <iostream>
using namespace std;

// this를 사용하는 이유 1. 해당 객체의 멤버 변수임을 지칭하기 위해 사용
class Int32 
{
	int val;

public:
	Int32(int val) { // Int32 전역 전역변수 val 값 대입 함수
		this->val = val;
	}

	void setValue(int val) { //val 값 대입 함수
		this->val = val;
	}

	void getValue() {
		cout << "val의 값은 : "<< this->val << endl;
	}
};

int main() {
	Int32 i32(10);
	i32.getValue();
	return 0;
}