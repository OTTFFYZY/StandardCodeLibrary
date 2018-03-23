#include <stdio.h>

const int M=1e5+5;
template<class T>
struct Stack
{
	T a[M]; int p;
	Stack()
	{
		p=0;
	}
	int size()
	{
		return p;
	}
	void push(T x)
	{
		a[p++]=x;
	}
	T top()
	{
		return a[p-1];
	}
	T pop()
	{
		p--;
	}
};

int main()
{
	return 0;
}