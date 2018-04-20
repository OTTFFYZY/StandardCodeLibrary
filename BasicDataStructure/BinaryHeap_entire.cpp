#include <stdio.h>
#include <algorithm>
using namespace std;

const int M=1e5+5;

struct Heap
{
	int h[M],n,cnt;// n is the number of element in the heap
	               // cnt is the number of element push in the heap 
	int id[M],pos[M]; //
	Heap() :n(0),cnt(0) {}
	Heap(int a[],int nn) :n(0),cnt(nn)
	{
		for(int i=0;i<nn;i++)
		{
			h[++n]==a[i];
			id[n]=pos[n]=n;
		}
		for(int i=n/2;i>=1;i--) sink(i);
	}
	void swim(int p)
	{
		int q=p>>1,x=h[p],y=id[p];
		while(q&&x<h[q])
		{
			h[p]=h[q];
			id[p]=id[q];
			pos[id[p]]=p;
			p=q;
			q=p>>1;
		}
		h[p]=x;
		id[p]=y;
		pos[y]=p;
	}
	void sink(int p)
	{
		int q=p<<1,x=h[p],y=id[p];
		while(q<=n)
		{
			if(q<n&&h[q+1]<h[q]) q++;
			if(h[q]>=x) break;
			h[p]=h[q];
			id[p]=id[q];
			pos[id[p]]=p;
			p=q;
			q=p<<1;
		}
		h[p]=x;
		id[p]=y;
		pos[y]=p;
	}
	
	void push(int x)
	{
		h[++n]=x;
		id[n]=++cnt;
		pos[id[n]]=n;
		swim(n);
	}
	int pop()
	{
		int r=h[1];
		swap(h[1],h[n]);
		swap(id[1],id[n--]);
		pos[id[1]]=1;
		sink(1);
		return r;
	}
	void erase(int i)
	{
		h[pos[i]]=INT_MIN;
		swim(pos[i]);
		pop();
	}
	void change(int i,int val)
	{
		h[pos[i]]=val;
		sink(pos[i]);
		swim(pos[i]);
	}
	int get_kpush(int k)
	{
		return h[pos[k]];
	}

};

int main()
{
	return 0;
}