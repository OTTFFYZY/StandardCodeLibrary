#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MV=1e5+5;
struct Edge
{
	int v;
	bool isb; //is bridge
	Edge(int v=0,bool isb=0):v(v),isb(isb){}
};
vector<Edge> g[MV];
int nv;
int dfn[MV],ndfn;
int col[MV],ncol;

int tarjan(int u,int fa)
{
	int lowu=dfn[u]=++ndfn,lowv;
	int v;
	for(Edge &e:g[u])
	{
		v=e.v;
		if(!dfn[v])
		{
			lowv=tarjan(v,u);
			lowu=min(lowu,lowv);
			if(lowv>dfn[u]) e.isb=1;
		}
		else if(dfn[v]<dfn[u]&&v!=fa)
			lowu=min(lowu,dfn[v]);
	}
	return lowu;
}
void dfs(int u)
{
	col[u]=ncol;
	for(Edge e:g[u])
	{
		if(e.isb||col[e.v]!=-1) continue;
		dfs(v);
	}
}
void find_ebc() // Edge Biconnectied Component
{
	memset(dfn,0,sizeof(dfn));
	ndfn=0;
	for(int i=0;i<nv;i++)
		tarjan(nv,-1);
	memset(col,-1,sizeof(col));// from 0
	ncol=0;
	for(int i=0;i<nv;i++)
		if(col[i]==-1)
		{
			dfs(i);
			ncol++;
		}
}


int main()
{
	return 0;
}