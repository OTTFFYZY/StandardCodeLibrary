#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;
const int MV=1005;
const int ME=1e5+5;

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
	g[u].emplace_back(v,0,g[v].size());
	g[v].emplace_back(u,0,g[u].size()-1);
	deg[u]++; deg[v]++;
}

stack<int> ansv;
stack<PII> anse;

int cur[MV];

void dfs(int u)
{
	for(int &i=cur[u];i<g[u].size();i++)
	{
		if(g[u][i].vis) continue;
		Edge &e=g[u][i];
		e.vis=1; g[e.v][e.rev].vis=1;
		dfs(u);
		anse.push_back(u,e.v);
	}
	ansv.push_back(u);
}

bool eulerLoop()
{
	int cnt=0;
	for(int i=0;i<nv;i++)
		if(deg[i]&1) cnt++;
	if(!cnt) return 0;
	while(!ansv.empty()) ansv.pop();
	while(!anse.empty()) anse.pop();
	memset(cur,0,sizeof(cur));
	dfs(0);
	return anse.size()==ne;
}

int st,ed;
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