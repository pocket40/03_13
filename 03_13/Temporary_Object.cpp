//�ӽ� ��ü�� ���α׷��� ���� ���߿� ��� ��� �����Ǿ��� ������� ��ü�� �ǹ�
//�ӽ� ��ü�� �̸��� ���� ������ �̸� ���� ��ü��� ��

#include <cstdio>
#include <iostream>
using namespace std;

class Int32
{
	int val;
public:
	Int32(int v = 0) : val(v) {
		cout << "Int32(" << v << ")" << endl;
	}

	~Int32() { cout << "~Int32()" << endl; }
};

int main() {
	Int32 i32(10); // ���� ��ü, �̸� ����
	Int32(20); // �ӽ� ��ü, �̸�����
	getchar();

	return 0;
}