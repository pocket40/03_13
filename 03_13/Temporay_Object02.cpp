//임시 객체는 프로그램의 성능이나 수행 속도를 떨어뜨리는 원인이 될 수 있으므로 임시 객체의 생성을 막아야 함
//다음과 같이 어떤 함수가 객체를 값으로 반환할 경우, 임시 객체가 생성됨

#include <iostream>
using namespace std;

class Int32
{
	int val;

public:
	Int32(int value = 0) :val(value) {
		cout << "Int32(" << value << ")" << endl;
	}

	Int32(const Int32& o) :val(o.val) {
		cout << "Int32(Int32(" << o.val << "))" << endl;
	}

	~Int32() { cout << "~Int32()" << endl; }

	Int32 operator+(const Int32& int32) {
		Int32 ret(val + int32.val);
		return ret; // return Int32(ret)
	}
};

int main() {
	Int32 a(1);
	Int32 b(2);
	Int32 z;

	getchar();
	z = a + b; // z = Int32(ret);
	getchar();

	return 0;
}