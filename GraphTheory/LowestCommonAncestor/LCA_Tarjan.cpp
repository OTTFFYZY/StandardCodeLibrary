#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MV=1e5+5;
const int MQ=1e5+5;
typedef pair<int,int> PII;

vector<int> g[MV];
int nv,ne;
void add_edge(int a,int b)
{
	g[a].push_back(b);
	g[b].push_back(a);
}

struct Query
{
	int v,id;
	Query(int v=0,int id=0):v(v),id(id){}
};
vector<Query> q[MQ];
int ans[MQ],cntq,nq;
void add_query(int a,int b)
{
	q[a].emplace_back(b,nq);
	q[b].emplace_back(a,nq++);
}

int uf[MV],vis[MV];
int uf_find(int x)
{
	return x==uf[x]?x:uf[x]=uf_find(uf[x]);
}
void lca_init()
{
	memset(vis,0,sizeof(vis));
	int a,b;
	for(int i=0;i<ne;i++)
	{
		scanf("%d%d",&a,&b);
		add_edge(a,b);
	}
	nq=0;
	for(int i=0;i<cntq;i++)
	{
		scanf("%d%d",&a,&b);
		add_query(a,b);
	}
}

void dfs(int u,int fa)
{
	uf[u]=u;
	vis[u]=1;
	for(int v:g[u])
		if(v!=fa)
		{
			dfs(v,u);
			uf[v]=u;
		}
	for(Query v:q[u])
	{
		if(vis[v.v]) ans[v.id]=uf_find(v.v);
	}

}
void lca(int root)
{
	lca_init();
	dfs(root,root);
}

int main()
{
	return 0;
}