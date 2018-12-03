#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
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

vector<PII> g[MV];
int nv;
void add_edge(int u,int v,int w)
{
	g[u].emplace_back(v,w);
	g[v].emplace_back(u,w);
}

int vis[MV];
int prim()
{
	heap.init(nv-1);
	memset(vis,0,sizeof(vis));
	vis[0]=1;
	for(PII e:g[0])
		heap.change(e.first,e.second);
	int ans=0;
	for(int i=1;i<nv;i++)
	{
		PII e=heap.top();
		if(e.second==INF) return -1; // No MST
		int u=e.first;
		ans+=e.second;
		vis[u]=1;
		for(PII e:g[u])
			if(!vis[e.first])
				heap.change(e.first,e.second);
	}
	return ans;
}

int main()
{
	return 0;
}