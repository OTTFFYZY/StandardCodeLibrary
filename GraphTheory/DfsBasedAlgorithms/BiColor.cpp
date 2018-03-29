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
void add_edge(int a,int b) //undirected
{
	g[a].push_back(b);
	g[b].push_back(a);
}

int color[MV];
bool dfs(int u,int col) //if the graph cannot bi-color return true
{
	if(color[u]) return color[u]!=col;
	color[u]=col;
	for(auto v:g[u])
		if(dfs(v,3-col)) return 1;
	return 0;
}

int main()
{	
	int st,stcolor; // start vertex and its color
	dfs(st,stcolor);
	return 0;
}