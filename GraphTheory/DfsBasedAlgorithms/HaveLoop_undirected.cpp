#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


const int MV=1e5+5;//maximum number of vertices
vector<int> g[MV];
int nv;//number of vertices

void init()
{
	for(int i=0;i<MV;i++)
		g[i].clear();
}
void add_edge(int a,int b)
{
	g[a].push_back(b);
	g[b].push_back(a);
}

int vis[MV];
bool dfs(int u,int fa)  //undirected without self-loops and multiple edges
{
	if(vis[u]) return 1;
	vis[u]=1;
	for(auto v:g[u])
		if(v!=fa&&dfs(v,u)) return 1;
	return 0;
}
bool have_loop()    // return true if there is any loop in the graph
{
	memset(vis,0,sizeof(vis));
	for(int i=0;i<nv;i++)
		if(!vis[i]&&dfs(i,-1)) return 1;
	return 0;
}

bool dfs2(int u,int fa)  //undirected
{
	if(vis[u]) return 1;
	vis[u]=1;
	int cnt=0;
	for(auto v:g[u])
	{
		if(v==fa&&++cnt>1) return 1;
		else if(v!=fa&&dfs2(v,u)) return 1;
	}
	return 0;
}
bool have_loop2()    // return true if there is any loop in the graph
{
	memset(vis,0,sizeof(vis));
	for(int i=0;i<nv;i++)
		if(!vis[i]&&dfs2(i,-1)) return 1;
	return 0;
}

int main()
{	
	return 0;
}