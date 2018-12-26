#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

const int MV=1e5+5;
vector<int> g[MV],rg[MV];
int nv,ne;

void add_edge(int fr,int to)
{
	g[fr].push_back(to);
	rg[to].push_back(fr);
}

int df2n[MV],vis[MV],sccno[MV];
int nscc;
void dfs1(int u)
{
	vis[u]=1;
	for(int v:g[u])
		if(!vis[v]) dfs1(v);
	df2n[nscc++]=u;
}
void dfs2(int u)
{
	vis[u]=1;
	sccno[u]=nscc;
	for(int v:rg[u])
		if(!vis[v]) dfs2(v);
}

void scc_kosaraju()
{
	memset(vis,0,sizeof(vis));
	nscc=0;
	for(int i=0;i<nv;i++)
		if(!vis[i]) dfs1(i);
	memset(vis,0,sizeof(vis));
	nscc=0;
	for(int i=nv-1;i>=0;i--) //inverted sequence
		if(!vis[df2n[i]])
		{
			dfs2(df2n[i]);
			nscc++;
		}
}

int main()
{
	return 0;
}