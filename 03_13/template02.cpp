#include<iostream>
using namespace std;

//함수 탬플릿도 오버로딩이 가능함
template<typename T> void swap(T* p, T* q) {
	T temp = *p;
	*p = *q;
	*q = temp;
}

template<typename T> void swap(T a[], T b[], int len) {
	for (int i = 0; i < len; i++) 
	{
		T temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

int main() {
	char s1[] = "hello";
	char s2[] = "world";

	swap(s1, s2, 5);

	cout << "s1 = " << s1 << endl;
	cout << "s2=" << s2 << endl;

	return 0;
}