#include <iostream>
using namespace std;

// �Լ� ���ø��� ���� ���Ἲ�� �����Ƿ� �ݵ�� ���ø� �Լ��� ���� ���� �ȿ� �Լ� ���ø��� �Ϻ��ϰ� ���ǵǾ� �־�� ��

template<typename T> T Max(T a, T b) {
	return a > b ? a : b; // a = 1, b = 2 == 2
}

int main() {
	cout << Max(1, 2) << endl;
	return 0;
}