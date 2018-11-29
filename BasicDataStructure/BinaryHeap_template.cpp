#include <stdio.h>
using namespace std;

const int M=1e5+5;

// T need < and <= and =
template<class T>
struct Heap
{
	T h[M];
    int n;
	Heap():n(0){}
	Heap(T v[],int n):n(n)
	{
		for(int i=0;i<n;i++)
			h[i]=v[i];
		for(int i=n/2;i>0;i--)
			sink(i);
	}
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
	void change(int p,T x)
	{
		h[p]=x;
		swim(p);
		sink(p);
	}
	void erase(int p)
	{
		swap(h[p],h[n--]);
		sink(p);
	}
};

int main()
{
	return 0;
}
