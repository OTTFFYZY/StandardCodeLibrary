#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MV=1e5+5;
struct Edge
{
	int v,rev,isb; //is bridge
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
void find_bridge()
{
	memset(dfn,0,sizeof(dfn));
	ndfn=0;
	for(int i=0;i<nv;i++)
		if(!dfn[i]) dfs(i,-1);
}


int main()
{
	while(scanf("%d%d",&nv,&ne)!=EOF)
	{
		init();
		int u,v;
		for(int i=0;i<ne;i++)
		{
			scanf("%d%d",&u,&v);
			add_edge(u,v);
		}
		find_bridge();
		for(int u=0;u<nv;u++)
		{
			cout<<u<<":\n";
			for(Edge e:g[u])
				cout<<e.v<<" "<<e.isb<<endl;
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
/*
3 3
0 1
0 1
1 2

3 3
1 0
2 1
1 2
*/