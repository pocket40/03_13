//상수 멤버 함수(Content_Member_Function)

//상수 멤버 함수는 함수 내에서 멤버 변수의 값을 변경할 수 없는 함수를 의미함
//멤버 함수 내에서 멤버 변수의 값을 변경하지 않는다면 반드시 상수 함수를 선언해야 함
//상수 멤버 함수 선언 방법 - 리턴타입 함수이름([매개변수,...]) const;
//상수 멤버 함수를 사용하는 이유 .의도하지 않는 값의 변경을 금지하기 위함
#include <iostream>
using namespace std;

class Int32
{
	int val;
	 
public:
	Int32(int v = 0) : val(v) {}

	void display() const {
		cout << val << endl;
		//val = 0; // ERROR, this->val = 0;
	}
};

int main() {
	Int32 i32;
	i32.display();

	return 0;
}

