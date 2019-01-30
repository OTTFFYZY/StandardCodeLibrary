#include <iostrea>
#include <stdio.h>
using namespace std;

const int M=5e4+5;
vector<int> g[M];
int root,nv;

int dep[M],fa[M],sz[M],son[M],top[M];
int dfn[M],id[M],ndfn;

void dfs1(int u,int f,int d)
{
	dep[u]=d;
	sz[u]=1;
	fa[u]=f;
	son[u]=-1;
	for(int v:g[u])
	{
		if(v==f) continue;
		dfs1(v,u,d+1);
		sz[u]+=sz[v];
		if(son[u]==-1||sz[son[u]]<sz[v])
			son[u]=v;
	}
}

void dfs2(int u,int f,int t)
{
	dfn[u]=++ndfn;
	id[ndfn]=u;
	top[u]=t;
	if(son[u]!=-1)
		dfs2(son[u],u,t);
	for(int v:g[u])
	{
		if(v==f||v==son[u]) continue;
		dfs2(v,u,v);
	}
}

void init_tcp()
{
	dfs1(root,-1,0);
	ndfn=0;
	dfs2(root,-1,root);
}

void updpath(int a,int b,int v)
{
	while(top[a]!=top[b])
	{
		if(dep[top[a]]<dep[top[b]]) // let top[a] deeper
			swap(a,b);
		// data structure update
		upd(dfn[top[a]],dfn[a],v);
		a=fa[top[a]];
	}
	if(dep[a]>dep[b]) // let b deeper
		swap(a,b);
	upd(dfn[a],dfn[b],v);
}

int qpath(int a,int b)
{
	int ans=0;
	while(top[a]!=top[b])
	{
		if(dep[top[a]]<dep[top[b]]) // let top[a] deeper
			swap(a,b);
		// data structure query
		ans+=query(dfn[top[a]],dfn[a]);
		a=fa[top[a]];
	}
	if(dep[a]>dep[b]) // let b deeper
		swap(a,b);
	ans+=query(dfn[a],dfn[b]);
	return ans;
}

void updsubt(int a,int v)
{
	upd(dfn[a],dfn[a]+sz[a]-1,v);
}

int qsubt(int a)
{
	return query(dfn[a],dfn[a]+sz[a]-1);
}

int main()
{
	return 0;
}