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
	for(int i=0;i<nv;i++)
		g[i].clear();
}
void add_edge(int fr,int to) //directed
{
	g[fr].push_back(to);
}


int vis[MV];
int topo[MV],ord[MV],p; // ans
bool dfs(int u)
{
	if(vis[u]==1) return 1;
	if(vis[u]==2) return 0;
	vis[u]=1;
	for(auto v:g[u])
		if(dfs(v)) return 1;
	vis[u]=2;
	topo[--p]=u;
	ord[u]=p;
	return 0;
}
bool topo_sort()   // if cannot do topo_sort return false
{
	memset(vis,0,sizeof(vis));
	p=nv;
	for(int i=0;i<nv;i++)
		if(!vis[i]&&dfs(i)) return 0;
	return 1;
}

int main()
{	
	return 0;
}