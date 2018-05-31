#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int ME=1e5+5;
const int MV=1e5+5;
const int INF=0x3f3f3f3f;
struct Edge
{
	int v,d;
	Edge(int v=0,int d=0):v(v),d(d){}
};
vector<Edge> g[MV];
int nv,ne;
int ind[MV],d[MV];

void init()
{
	memset(ind,0,sizeof(ind));
	for(int i=0;i<nv;i++) g[i].clear();
}

void add_edge(int fr,int to,int d)
{
	g[fr].emplace_back(to,d);
	ind[to]++;
}
queue<int> qu;
void splp_dag(int st)
{
	memset(d,INF,sizeof(d)); //shortest path
	//memset(d,-INF,sizeof(d)); //longest path
	while(!qu.empty()) qu.pop();
	for(int i=0;i<nv;i++) if(!ind[i]) qu.push(i);
	d[st]=0;
	while(!qu.empty())
	{
		int u=qu.front(); qu.pop();
		for(auto e:g[u])
		{
			if(!--ind[e.v]) qu.push(e.v);
			if(d[u]!=INF)
				d[e.v]=min(d[e.v],d[u]+e.d); //shortest path
			//if(d[u]!=-INF)
			//	d[e.v]=max(d[e.v],d[u]+e.d); //longest path
		}
	}
}

int main()
{
	return 0;
}