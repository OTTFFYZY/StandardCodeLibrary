#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MV=1e5+5;
vector<int> g[MV];
int nv;

int deg[MV];

void init()
{
	memset(deg,0,sizeof(deg));
	for(int i=0;i<nv;i++)
		g[i].clear();
}

void addEdge(int u,int v)
{
	g[u].push_back(v);
	g[v].push_back(u);
	deg[u]++; deg[v]++;
}

int vis[MV];
void dfs(int u)
{
	vis[u]=1;
	for(int v:g[u])
		if(!vis[v]) dfs(v);
}

bool hasLoop()
{
	int cnt=0;
	for(int i=0;i<nv;i++)
		if(deg[i]&1) cnt++;
	if(!cnt) return 0;

	memset(vis,0,sizeof(vis));
	dfs(0);
	for(int i=0;i<nv;i++)
		if(!vis[i]) return 0;
	return 1;
}

int st,ed;
bool hasPath()
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
	memset(vis,0,sizeof(vis));
	dfs(0);
	for(int i=0;i<nv;i++)
		if(!vis[i]) return 0;
	if(!cnt) st=ed=0;
	return 1;
}

int main()
{
	return 0;
}