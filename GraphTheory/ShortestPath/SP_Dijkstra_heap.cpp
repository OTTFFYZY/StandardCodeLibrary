#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int MV=1e5+5;
const int ME=1e5+5;
const int INF=0x3f3f3f3f;
typedef pair<int,int> PII;

struct Heap
{
	int h[MV],id[MV],pos[MV];
	int n;
	void init(int n)
	{
		for(int i=1;i<=n;i++)
		{
			h[i]=INF;
			id[i]=pos[i]=i;
		}
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
		pos[id[p]]=p;
	}
	void swim(int p)
	{
		int q=p>>1,x=h[p],y=id[p];
		while(q&&h[q]>x)
		{
			h[p]=h[q];
			id[p]=id[q];
			pos[id[p]]=p;
			p=q;
			q=p>>1;
		}
		h[p]=x;
		id[p]=y;
		pos[id[p]]=p;
	}
	PII top()
	{
		PII ans(h[1],id[1]);
		swap(h[1],h[n]);
		swap(id[1],id[n--]);
		pos[id[1]]=1;
		sink(1);
		return ans;
	}
	void change(int i,int v)
	{
		if(h[pos[i]]<=v)
			return;
		h[pos[i]]=v;
		swim(pos[i]);
	}
}heap;

int vis[MV],d[MV];

void dij(int s)
{
	memset(vis,0,sizeof(vis));
	memset(d,0x3f,sizeof(d));
	d[s]=0;
	heap.init(nv);
	change(s,0);
}