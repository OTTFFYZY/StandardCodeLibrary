#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;
const int MV=55;
const int ME=1005;

struct Edge
{
	int v,nxt,vis;
	Edge(int v=0,int nxt=0,int vis=0)
		:v(v),nxt(nxt),vis(vis){}
}edges[ME*2];
int head[MV],nne;

int nv=50,ne;
int deg[MV];

void init()
{
	memset(head,-1,sizeof(head));
	nne=0;
	memset(deg,0,sizeof(deg));
}

void add_edge(int u,int v)
{
	edges[nne]=Edge(v,head[u],0);
	head[u]=nne++;
	edges[nne]=Edge(u,head[v],0);
	head[v]=nne++;
	deg[u]++; deg[v]++;
}

stack<int> ansv;
stack<PII> anse;

int cur[MV];

void dfs(int u)
{
	for(int &i=head[u];i!=-1;i=edges[i].nxt)
	{
		Edge &e=edges[i];
		if(e.vis) continue;
		e.vis=1; edges[i^1].vis=1;
		dfs(e.v);
		anse.emplace(u,e.v);
	}
}

int st;
bool eulerLoop()
{
	for(int i=1;i<=nv;i++)
		if(deg[i]&1) return 0;
	while(!ansv.empty()) ansv.pop();
	while(!anse.empty()) anse.pop();
	memset(cur,0,sizeof(cur));
	dfs(st);
	return anse.size()==ne;
}