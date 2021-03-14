//���� ����� Ȱ�� .������ ��ü�� �����ؾ� �� ���

#include <iostream>
using namespace std;

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&);
	void operator=(const Cursor&);

public:
	static Cursor& getInstance() {
		static Cursor  cursor;
		return cursor;
	}
};

int main() {
	//Cursor cursor; // ERROR

	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	cout << &c1 << endl;
	cout << &c2 << endl;

	return 0;
}