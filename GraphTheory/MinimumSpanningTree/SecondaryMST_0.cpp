#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int M=2e5+5;
const int MB=19;
const int INF=0x3f3f3f3f;
const int INFL=0x3f3f3f3f3f3f3f3f;

int n,m;
typedef pair<int,int> PII;
vector<PII> g[M];
LL ans[M];

struct Edge
{
	int u,v,w;
	int id;
	int inmst;
	void read(int i)
	{
		id=i; 
		inmst=0;
		scanf("%d%d%d",&u,&v,&w);
	}
	bool operator<(const Edge &B) const
	{
		return w<B.w;
	}
}edges[M];

int uf[M];
int find(int x)
{
	return x==uf[x]?x:uf[x]=find(uf[x]);
}
LL kruskal()
{
	sort(edges,edges+m);
	for(int i=1;i<=n;i++)
		uf[i]=i;
	int cnt=1;
	LL sum=0;
	for(int i=0;i<m;i++)
	{
		int u=find(edges[i].u),v=find(edges[i].v);
		if(u==v) continue;
		sum+=edges[i].w;
		edges[i].inmst=1;
		uf[u]=v;
		g[edges[i].u].emplace_back(edges[i].v,edges[i].w);
		g[edges[i].v].emplace_back(edges[i].u,edges[i].w);
		if(++cnt==n) break;
	}
	return sum;
}

int dep[M];
int fa[M][MB];
int ma[M][MB];

void dfs(int u,int f,int d)
{
	dep[u]=d;
	fa[u][0]=f;
	for(auto e:g[u])
	{
		int v=e.first;
		if(v==f)
		{
			ma[u][0]=e.second;
			continue;
		}
		dfs(v,u,d+1);
	}
}

void init_lca()
{
	dfs(1,0,0);
	for(int i=1;i<MB;i++)
	{
		for(int u=1;u<=n;u++)
		{
			fa[u][i]=fa[fa[u][i-1]][i-1];
			ma[u][i]=max(ma[u][i-1],ma[fa[u][i-1]][i-1]);
		}
	}
}

int getma(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	int d=dep[u]-dep[v];
	int ans=0;
	for(int i=0;i<MB;i++)
		if(d&(1<<i))
		{
			ans=max(ans,ma[u][i]);
			u=fa[u][i];
		}
	if(u==v) return ans;
	for(int i=MB-1;i>=0;i--)
	{
		if(fa[u][i]!=fa[v][i])
		{
			ans=max(ans,ma[u][i]);
			ans=max(ans,ma[v][i]);
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	ans=max(ans,ma[u][0]);
	ans=max(ans,ma[v][0]);
	return ans;
}

LL SMST()
{
	LL sum=kruskal();
	init_lca();
	LL ans=INFL;
	for(int i=0;i<m;i++)
	{
		if(edges[i].inmst) continue;
		ans=min(ans,sum-getma(edges[i].u,edges[i].v)+edges[i].w);
	}
	return ans;
}

int main()
{

	return 0;
}