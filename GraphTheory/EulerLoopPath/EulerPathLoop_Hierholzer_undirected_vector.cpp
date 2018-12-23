#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;
const int MV=55;
//const int ME=1e5+5;

struct Edge
{
	int v,vis,rev;
	Edge(int v=0,int vis=0,int rev=0)
		:v(v),vis(vis),rev(rev){}
};

vector<Edge> g[MV];
int nv,ne;
int deg[MV];

void init()
{
	for(int i=0;i<nv;i++)
		g[i].clear();
	memset(deg,0,sizeof(deg));
}

void add_edge(int u,int v)
{
	if(u==v) //self loop
		g[u].emplace_back(v,0,g[v].size()+1);
	else
		g[u].emplace_back(v,0,g[v].size());
	g[v].emplace_back(u,0,g[u].size()-1);
	deg[u]++; deg[v]++;
}

stack<int> ansv;
stack<PII> anse;

int cur[MV];

void dfs(int u)
{
	//for(int i=0;i<g[u].size();i++)
	for(int &i=cur[u];i<g[u].size();i++)
	{
		if(g[u][i].vis) continue;
		Edge &e=g[u][i];
		e.vis=1; g[e.v][e.rev].vis=1;
		dfs(e.v);
		anse.emplace(u,e.v);
	}
}

int st,ed;
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

bool eulerPath()
{
	int cnt=0; st=ed=-1;
	for(int i=0;i<nv;i++)
		if(deg[i]&1)
		{
			cnt++;
			if(st==-1)
				st=i;
			else if(ed==-1)
				ed=i;
		}
	if(cnt!=0&&cnt!=2) return 0;
	if(cnt==0) st=ed=0;
	while(!ansv.empty()) ansv.pop();
	while(!anse.empty()) anse.pop();
	memset(cur,0,sizeof(cur));
	dfs(st);
	return anse.size()==ne;
}

int main()
{

	return 0;
}