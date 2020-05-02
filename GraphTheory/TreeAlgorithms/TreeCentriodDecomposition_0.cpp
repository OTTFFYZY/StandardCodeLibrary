#include <bits/stdc++.h>
using namespace std;

const int M=1e5+5;

namespace CentriodDecomposition
{
	vector<int> g[M];
	int n;

	int vis[M];
	int sz[M];
	int mx[M]; // max subtree size

	int root,totsz;

	void dfs_cal()
	{
		// do something
	}
	void dfs_root(int u,int fa)
	{
		sz[u]=1; mx[u]=0;
		for(int v:g[u])
		{
			if(v==fa||vis[v]) continue;
			dfs_root(v,u);
			sz[u]+=sz[v];
			mx[u]=max(mx[u],sz[v]);
		}
		mx[u]=max(mx[u],totsz-sz[u]);
		if(root==-1||mx[u]<mx[root])
			root=u;
	}
	void dfs(int u) // main func
	{
		vis[u]=1;
		dfs_cal(u);
		for(int v:g[u])
		{
			int v=e.first;
			if(vis[v]) continue;
			totsz=sz[v]; root=-1;
			dfs_root(v,0);
			fa[v]=u;
			dfs(root);
		}
	}
};
using namespace CentriodDecomposition;

int main()
{
	return 0;
}