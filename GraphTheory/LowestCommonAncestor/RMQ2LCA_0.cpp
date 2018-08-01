#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;
const int M=1e5+5;
const int MQ=1e5+5;
int a[M]={2,4,3,1,6,7,8,9,1,7};
//        0,1,2,3,4,5,6,7,8,9
PII rmqq[M];
int na=10,cntq;

vector<int> g[M];
int fa[M];
int st[M],stp;
void rmq2lca()
{
	stp=0;
	for(int i=0;i<na;i++)
	{
		int k=stp;
		while(k&&a[st[k]]>a[i]) k--;
		if(k) fa[i]=st[k];
		if(k<stp) fa[st[k+1]]=i;
		st[++k]=i;
		stp=k;
	}
	fa[st[1]]=-1;
}

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
int ans[MQ],nq;
void add_query(int a,int b)
{
	q[a].emplace_back(b,nq);
	q[b].emplace_back(a,nq++);
}

int uf[M],vis[M];
int uf_find(int x)
{
	return x==uf[x]?x:uf[x]=uf_find(uf[x]);
}
int lca_init()
{
	int root;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<nv;i++)
	{
		if(fa[i]!=-1) add_edge(i,fa[i]);
		else root=i;
	}
	nq=0;
	for(int i=0;i<cntq;i++)
		add_query(rmqq[i].first,rmqq[i].second);
	return root;
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
		if(vis[v.v]) ans[v.id]=a[uf_find(v.v)];
}
void lca() //main process
{
	int root=lca_init();
	dfs(root,root);
}

int main()
{
	rmq2lca();
	for(int i=0;i<10;i++)
		cout<<i<<" "<<fa[i]<<endl;
	lca();
	return 0;
}