//��� ��� �Լ�(Content_Member_Function)

//��� ��� �Լ��� �Լ� ������ ��� ������ ���� ������ �� ���� �Լ��� �ǹ���
//��� �Լ� ������ ��� ������ ���� �������� �ʴ´ٸ� �ݵ�� ��� �Լ��� �����ؾ� ��
//��� ��� �Լ� ���� ��� - ����Ÿ�� �Լ��̸�([�Ű�����,...]) const;
//��� ��� �Լ��� ����ϴ� ���� .�ǵ����� �ʴ� ���� ������ �����ϱ� ����
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

