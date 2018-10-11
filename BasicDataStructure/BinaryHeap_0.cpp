#include <stdio.h>
using namespace std;

const int M=1e5+5;

struct Heap
{
	int h[M],n; // root at h[1]
	Heap(int n=0):n(n) // O(n) 
	{
		for(int i=n/2;i>0;i--)
			sink(i);
	}
	void swim(int p)
	{
		int q=p>>1,x=h[p];
		while(q&&x<h[q])
		{
			h[p]=h[q];
			p=q;
			q=p>>1;
		}
		h[p]=x;
	}
	void push(int x)
	{
		h[++n]=x;
		swim(n);
	}
	void sink(int p)
	{
		int q=p<<1,x=h[p];
		while(q<=n)
		{
			if(q<n&&h[q+1]<h[q]) q++;
			if(h[q]>=x) break;
			h[p]=h[q];
			p=q;
			q=p<<1;
		}
		h[p]=x;
	}
	int pop()
	{
		int r=h[1];
		h[1]=h[n--];
		sink(1);
		return r;
	}
};

int main()
{
	return 0;
}