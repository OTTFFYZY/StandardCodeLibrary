#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

const int MV=1e5+5;
vector<int> g[MV],tg[MV];
void add_edge(int fr,int to)
{
	g[fr].push_back(to);
	tg[to].push_back(fr);
}

int num[MV],vis[MV],scc[MV];
int ncnt;
void dfs1(int u)
{
	vis[u]=1;
	for(int v:g[u])
		if(!vis[v]) dfs1(v);
	num[ncnt++]=u;
}
void dfs2(int u)
{
	vis[u]=1;
	scc[u]=ncnt;
	for(int v:tg[u])
		if(!vis[v]) dfs2(v);
}

void kosaraju(int nv)
{
	memset(vis,0,sizeof(vis));
	int ncnt=0;
	for(int i=0;i<nv;i++)
		if(!vis[i]) dfs1(i);
	memset(vis,0,sizeof(vis));
	ncnt=0;
	for(int i=nv-1;i>=0;i--) //inverted sequence
		if(!vis[num[i]])
		{
			dfs2(num[i]);
			ncnt++;
		}
}

int main()
{
	return 0;
}