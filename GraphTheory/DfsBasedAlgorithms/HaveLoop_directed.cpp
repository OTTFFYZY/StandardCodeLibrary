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
void add_edge(int fr,int to) //directed
{
	g[fr].push_back(to);
}

int vis[MV];
bool dfs(int u)
{
	if(vis[u]) return vis[u]=1;
	vis[u]=1;
	for(auto v:g[u])
		if(dfs(v)) return 1;
	vis[u]=2;
	return 0;
}
bool have_loop()    // return true if there is any loop in the graph
{
	for(int i=0;i<nv;i++)
		if(!vis[i]&&dfs(i)) return 1;
	return 0;
}

int main()
{	
	return 0;
}