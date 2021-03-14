//������ ������ ��ü�� ����Ͽ� �����ϴ� ���α׷��� �����

#include<iostream>
using namespace std;

template <typename T> class Stack
{
private:
	T* arr;
	int top;
	int size;

public:
	Stack(int size = 5) { // ������
		arr = new T[size]; // ���� �Ҵ�
		size = size;
		top = 0;
	}

	~Stack() { delete[] arr; } //�Ҹ��ڷ� �����Ҵ� ����

	bool isFull() { return (top == size); }
	bool isEmpty() { return (top == 0); }

	void push(const T& data) { arr[top++] = data; } // arr[top++] top == 0  //arr[0] = data;
	T& pop() { return arr[--top]; }
};

int main() {
	Stack<int> s; // Stack == class // Stack s(5);

	s.push(10);
	s.push(20);

	cout << s.pop() << endl;
	cout << s.pop() << endl;

	return  0;
}