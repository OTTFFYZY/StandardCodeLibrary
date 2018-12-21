#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MV=1e5+5;
vector<int> g[MV];
int nv;

int ind[MV],otd[MV];

void init()
{
	memset(ind,0,sizeof(ind));
	memset(otd,0,sizeof(otd));
	for(int i=0;i<nv;i++)
		g[i].clear();
}

void addEdge(int u,int v)
{
	g[u].push_back(v);
	ind[u]++; otd[v]++;
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
	for(int i=0;i<nv;i++)
		if(ind[i]!=otd[i]) return 0;

	memset(vis,0,sizeof(vis));
	dfs(0);
	for(int i=0;i<nv;i++)
		if(!vis[i]) return 0;
	return 1;
}

int st,ed;
bool hasPath()
{
	st=ed=-1;
	for(int i=0;i<nv;i++)
	{
		if(ind[i]==otd[i]) continue;
		else if(ind[i]+1==otd[i])
		{
			if(st!=-1) return 0;
			st=i;
		}
		else if(ind[i]==otd[i]+1)
		{
			if(ed!=-1) return 0;
			ed=i;
		}
		else return 0;
	}
	if(st==-1&&ed==-1) st=ed=0;
	if(st==-1&&ed!=-1||st!=-1&&ed==-1) return 0;
	
	memset(vis,0,sizeof(vis));
	dfs(st);
	for(int i=0;i<nv;i++)
		if(!vis[i]) return 0;
	return 1;
}

int main()
{
	return 0;
}