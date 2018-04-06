#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int M=1e5+5;
const int MB=20;

vector<int> g[M];
int nv;

int fa[M][MB],dep[M];
void dfs_fa(int u,int depth)
{
	dep[u]=depth;
	for(int v:g[u])
		if(fa[v][0]==-1)
		{
			fa[v][0]=u;
			dfs_fa(v,depth+1);
		}
}
void init(int root)
{
	memset(fa,-1,sizeof(fa));
	dfs_fa(root,0);
	for(int j=1;j<MB;j++)
		for(int i=0;i<nv;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
}
int lca(int a,int b)
{
	if(dep[a]>dep[b]) swap(a,b);
	int k=dep[b]-dep[a];
	for(int i=0;(1<<i)<=k;i++)
		if(k&(1<<i)) b=fa[b][i];
	if(a==b) return a;
	for(int i=MB-1;i>=0;i--)
	{
		if(fa[a][i]!=fa[b][i])
		{
			a=fa[a][i];
			b=fa[b][i];
		}
	}
	return fa[a][0];
}


int main()
{
	return 0;
}