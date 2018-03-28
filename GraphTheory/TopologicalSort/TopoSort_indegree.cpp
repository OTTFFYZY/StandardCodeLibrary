#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;


const int MV=1e5+5;//maximum number of vertices
vector<int> g[MV];
int ind[MV];
int nv;//number of vertices

void init()
{
	memset(ind,0,sizeof(ind));
	for(int i=0;i<nv;i++)
		g[i].clear();
}
void add_edge(int fr,int to) //directed
{
	g[fr].push_back(to);
	ind[to]++;
}

int topo[MV]; // ans
queue<int> qu;
bool topo_sort()   // if cannot do topo_sort return false
{
	while(!qu.empty()) qu.pop();
	for(int i=0;i<nv;i++)
		if(!ind[i]) qu.push(i);
	int p=0;
	while(!qu.empty())
	{
		int u=qu.front(); qu.pop();
		topo[p++]=u;
		for(int v:g[u])
			if(--ind[v]) qu.push(v);
	}
	return p==nv;
}

int main()
{	
	return 0;
}