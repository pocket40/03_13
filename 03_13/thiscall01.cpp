//객체의 주소와 함께 호출되는 방식
#include <iostream>
using namespace std;

class Int32
{
	int val;

public:
	void setValue(int val) { // void setValue(Int32* const this, int val)
		this->val = val;
		//this = 0; // ERROR
	}
};

int main() {
	Int32 i32;
	i32.setValue(10); // Int32::setValue(&i32, 10);

	return 0;
}