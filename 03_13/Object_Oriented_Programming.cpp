//독립된 단위인 객체를 사용하여 구현하는 프로그래밍 방법론

#include<iostream>
using namespace std;

template <typename T> class Stack
{
private:
	T* arr;
	int top;
	int size;

public:
	Stack(int size = 5) { // 생성자
		arr = new T[size]; // 동적 할당
		size = size;
		top = 0;
	}

	~Stack() { delete[] arr; } //소멸자로 동적할당 삭제

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