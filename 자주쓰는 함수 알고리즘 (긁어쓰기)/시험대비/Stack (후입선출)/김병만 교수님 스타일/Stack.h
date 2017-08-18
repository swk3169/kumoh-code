#pragma once
#include <iostream>

using namespace std;

const int capacity = 10;

template <typename T>
class Stack // Stack 후입선출 (Last In First Out)
{
private:
	T* stack;
	T data;
	int top;
public:
	Stack()
	{
		top = -1; // 스택에 아무런 데이터가 없다는 것을 알림
		stack = new T[capacity]; // 동적배열에 스택의 크기를 할당
	}
	~Stack() { delete[] stack; }

	void init()
	{
		cout << "top: " << top << " capacity: " << capacity << endl;
	}

	T& get() const
	{
		return stack[top];
	}

	bool isFull() const // 스택의 공간이 가득차지 않았나를 검사한다.
	{
		if (top == capacity - 1) // 스택이 포화상태일때
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isEmpty() const // 스택의 공간이 비어있는지 검사한다.
	{
		if (top == -1) // 스택에 아무런 데이터가 없을때
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Push(const T& data) // 스택의 공간에 데이터를 맨 밑에부터 쌓는다.
	{
		if (isFull() == true)
		{
			throw "OverFlow";
		}
		else
		{
			// -1로 초기화된 상태에서 증가하므로 0부터 공간이 생김
			stack[++top] = data; // 증가된 공간에 데이터 값을 할당
		}
	}

	T& Pop() // 스택의 공간에 데이터를 맨 위부터 비운다.
	{
		if (isEmpty() == true)
		{
			throw "UnderFlow";
		}
		else
		{
			return stack[top--]; // 마지막 데이터값에서 증감하므로 마지막으로부터 전의 데이터를 보여주게 됨
		}
	}

	void Show() // 스택의 현재 공간을 보여준다.
	{
		cout << "Stack의 현재공간" << endl;
		for (int i = 0; i <= top; i++)
		{
			cout << stack[i] << endl;
		}
	}
};