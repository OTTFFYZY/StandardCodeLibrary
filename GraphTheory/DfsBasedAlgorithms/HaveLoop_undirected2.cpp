#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


const int MV=1e5+5;//maximum number of vertices
vector<int> g[MV];
int nv;//number of vertices
int ne;//number of edges

void init()
{
	for(int i=0;i<MV;i++)
		g[i].clear();
}
void add_edge(int a,int b) //undirected with self-loops and multiple edges
{
	g[a].push_back(b);
	g[b].push_back(a);
}

int vis[MV];
void dfs(int u)
{
	if(vis[u]) return;
	vis[u]=1;
	for(int v:g[u]) dfs(v);
}
bool have_loop()    // return true if there is any loop in the graph
{
	int cnt=0;  //number of connected block
	memset(vis,0,sizeof(vis));
	for(int i=0;i<nv;i++)
		if(!vis[i])
		{
			dfs(i);
			cnt++;
		} 
	return ne+cnt!=nv;
}

int main()
{	
	return 0;
}