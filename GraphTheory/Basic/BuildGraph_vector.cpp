#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


const int MV=1e5+5;//number of vertices
vector<pair<int,int> > g[MV];

void init()
{
	for(int i=0;i<MV;i++)
		g[i].clear();
}
void add_edge(int fr,int to,int w) //directed
{
	g[fr].emplace_back(to,w);
}
void add_edge2(int a,int b,int w) //undirected
{
	g[a].emplace_back(b,w);
	g[b].emplace_back(a,w);
}

int main()
{
	//traverse u's adjacent vertices
	int u=0;
	for(auto v:g[u])
	{
		v.first; v.second;
	}
	return 0;
}