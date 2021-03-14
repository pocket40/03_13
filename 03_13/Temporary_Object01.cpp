//임시 객체는 컴파일러의 필요에 의해 만들어짐

#include <iostream>
using namespace std;

class Int32
{
	int val;
public:
	Int32(int value = 0) : val(value) {
		cout << "Int32(" << value << ")" << endl;
	}

	Int32(const Int32& o) :val(o.val) {
		cout << "Int32(Int32(" << o.val << "))" << endl;
	}

	~Int32() { cout << "~Int32()" << endl; }

	Int32 operator+(const Int32& int32) {
		Int32 ret(val + int32.val);
		return ret;
	}
};

int main() {
	Int32 a(1);
	Int32 b(2);
	Int32 z;

	getchar();
	z = a + b; // z = Int32(3);
	getchar();

	return 0;
}