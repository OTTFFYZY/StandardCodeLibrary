#include <stdio.h>

const int M=1e5+5;
template<class T>
struct Queue
{
	T a[M]; int ph,pt;
	Queue()
	{
		ph=pt=0;
	}
	int size()
	{
		return pt-ph;
	}
	void push(T x)
	{
		a[pt++]=x;
	}
	T front()
	{
		return a[ph];
	}
	T pop()
	{
		ph++;
	}
};

int main()
{
	return 0;
}