//�ӽ� ��ü�� ���α׷��� �����̳� ���� �ӵ��� ����߸��� ������ �� �� �����Ƿ� �ӽ� ��ü�� ������ ���ƾ� ��
//������ ���� � �Լ��� ��ü�� ������ ��ȯ�� ���, �ӽ� ��ü�� ������

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