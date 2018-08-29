#include <stdio.h>
using namespace std;

const int M=1e5+5;

template<class T>
struct Heap
{
	T h[M];
    int n;
	Heap() :n(0) {}
	void swim(int p)
	{
		int q=p>>1;
        T x=h[p];
		while(q&&x<h[q])
		{
			h[p]=h[q];
			p=q;
			q=p>>1;
		}
		h[p]=x;
	}
	void push(T x)
	{
		h[++n]=x;
		swim(n);
	}
	void sink(int p)
	{
		int q=p<<1;
        T x=h[p];
		while(q<=n)
		{
			if(q<n&&h[q+1]<h[q]) q++;
			if(x<=h[q]) break;
			h[p]=h[q];
			p=q;
			q=p<<1;
		}
		h[p]=x;
	}
	int pop()
	{
		T r=h[1];
		h[1]=h[n--];
		sink(1);
		return r;
	}
};

int main()
{
	return 0;
}
