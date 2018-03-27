#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


const int MV=1e5+5;//number of vertices
vector<int> g[MV];

void init()
{
	for(int i=0;i<MV;i++)
		g[i].clear();
}
void add_edge(int fr,int to) //directed
{
	g[fr].push_back(to);
}
bool vis[MV];
void dfs(int u)  //for graph
{
	if(vis[u]) return;
	vis[u]=1;

	//operations for u
		
	for(auto v:g[u]) dfs(v);
}

void dfs2(int u,int fa)  //for tree
{

	//operations for u
		
	for(auto v:g[u]) if(v!=fa) dfs(v);
}

int main()
{
	init();
	memset(vis,0,sizeof(vis));
	int st=0;
	dfs(st);
	dfs2(st,-1);
	return 0;
}