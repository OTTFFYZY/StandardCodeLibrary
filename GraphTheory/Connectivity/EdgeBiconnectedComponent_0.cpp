#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MV=1005;

struct Edge
{
	int v,rev,isb;
	Edge(int v=0,int rev=0,int isb=0)
		:v(v),rev(rev),isb(isb){}
};
vector<Edge> g[MV];
int nv,ne;

void init()
{
	for(int i=0;i<nv;i++)
		g[i].clear();
}

void add_edge(int u,int v)
{
	g[u].emplace_back(v,g[v].size());
	g[v].emplace_back(u,g[u].size()-1);
}

int dfn[MV],ndfn;
int dfs(int u,int fa)
{
	int lowu=dfn[u]=++ndfn,lowv;
	int cnt=0;
	for(Edge &e:g[u])
	{
		int v=e.v;
		if(v==fa)
		{
			if(++cnt>1) // multiple edges      
				lowu=min(lowu,dfn[v]);
			continue;
		}
		if(!dfn[v])
		{
			lowv=dfs(v,u);
			lowu=min(lowu,lowv);
			if(lowv>dfn[u])
			{
				e.isb=1;
				g[v][e.rev].isb=1;
			}
		}
		else if(dfn[v]<dfn[u])
			lowu=min(lowu,dfn[v]);
	}
	return lowu;
}

int bccno[MV],nbcc;//ebcc;

void dfs2(int u)
{
	bccno[u]=nbcc;
	for(Edge e:g[u])
	{
		if(e.isb||bccno[e.v]!=-1)
			continue;
		dfs2(e.v);
	}
}

void find_ebcc()
{
	memset(dfn,0,sizeof(dfn)); ndfn=0;
	memset(bccno,-1,sizeof(bccno)); nbcc=0;
	for(int i=0;i<nv;i++)
		if(!dfn[i]) dfs(i,-1);
	for(int i=0;i<nv;i++)
		if(bccno[i]==-1)
		{
			dfs2(i);
			nbcc++;
		}
}

int main()
{
	return 0;
}