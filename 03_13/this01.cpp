#include <iostream>
using namespace std;

// this�� ����ϴ� ���� 1. �ش� ��ü�� ��� �������� ��Ī�ϱ� ���� ���
class Int32 
{
	int val;

public:
	Int32(int val) { // Int32 ���� �������� val �� ���� �Լ�
		this->val = val;
	}

	void setValue(int val) { //val �� ���� �Լ�
		this->val = val;
	}

	void getValue() {
		cout << "val�� ���� : "<< this->val << endl;
	}
};

int main() {
	Int32 i32(10);
	i32.getValue();
	return 0;
}