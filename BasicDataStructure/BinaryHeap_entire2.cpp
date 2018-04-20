#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=1e5+5;

struct Heap
{
	int h[M],n,cnt;// n is the number of element in the heap
	               // cnt is the number of element push in the heap 
	int pos[M];    // the position of val in the heap
	Heap() :n(0),cnt(0) {}
	Heap(int a[],int nn) :n(0),cnt(nn)
	{
		memset(pos,0,sizeof(pos));
		for(int i=0;i<nn;i++)
		{
			h[++n]=a[i];
			pos[h[n]]=n;
		}
		for(int i=n/2;i>=1;i--) sink(i);
	}
	void swim(int p)
	{
		int q=p>>1,x=h[p];
		while(q&&x<h[q])
		{
			h[p]=h[q];
			pos[h[p]]=p;
			p=q;
			q=p>>1;
		}
		h[p]=x;
		pos[x]=p;
	}
	void sink(int p)
	{
		int q=p<<1,x=h[p];
		while(q<=n)
		{
			if(q<n&&h[q+1]<h[q]) q++;
			if(h[q]>=x) break;
			h[p]=h[q];
			pos[h[p]]=p;
			p=q;
			q=p<<1;
		}
		h[p]=x;
		pos[x]=p;
	}
	
	void push(int x)
	{
		h[++n]=x;
		pos[x]=n;
		swim(n);
	}
	int pop()
	{
		int r=h[1];
		swap(h[1],h[n--]);
		pos[h[1]]=1;
		pos[r]=0;
		sink(1);
		return r;
	}
	void erase(int i)
	{
		h[pos[i]]=INT_MIN;
		swim(pos[i]);
		pos[i]=0;
		pop();
	}
	void change(int x,int y)//change v from x to y;
	{
		h[pos[x]]=y;
		pos[y]=pos[x];
		pos[x]=0;
		sink(pos[y]);
		swim(pos[y]);
	}
	int isk_inh(int k)
	{
		return pos[k];
	}

};

int main()
{
	return 0;
}