#include<iostream>
using namespace std;

// �ڱ� �ڽ��� ����Ű�� ������ ����� �ǹ�
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