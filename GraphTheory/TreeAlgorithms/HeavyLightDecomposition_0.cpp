#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int M=1e5+5;
const int INF=0x3f3f3f3f;
int n,m,root;
LL mo;

int val[M];

struct SegT
{
	LL sum[M*4],add[M*4];
	int L,R;
	LL V;
	void apply(int o,LL v,int l,int r)
	{
		sum[o]+=v*(r-l+1);
		add[o]+=v;
	}
	void push(int o,int l,int mid,int r)
	{
		if(add[o])
		{
			apply(o<<1,add[o],l,mid);
			apply(o<<1|1,add[o],mid+1,r);
			add[o]=0;
		}
	}
	void pull(int o)
	{
		sum[o]=sum[o<<1]+sum[o<<1|1];
	}
	void update_(int o,int l,int r)
	{
		if(L<=l&&r<=R)
		{
			apply(o,V,l,r);
			return;
		}
		int mid=(l+r)>>1;
		push(o,l,mid,r);
		if(L<=mid) update_(o<<1,l,mid);
		if(mid<R) update_(o<<1|1,mid+1,r);
		pull(o);
	}
	void update(int l,int r,LL v)
	{
		L=l; R=r; V=v;
		update_(1,1,n);
	}
	LL query(int o,int l,int r)
	{
		if(L<=l&&r<=R) return sum[o];
		int mid=(l+r)>>1;
		push(o,l,mid,r);
		LL ans=0;
		if(L<=mid) ans+=query(o<<1,l,mid);
		if(mid<R) ans+=query(o<<1|1,mid+1,r);
		return ans;
	}
	LL query(int l,int r)
	{
		L=l; R=r;
		return query(1,1,n);
	}
}segt;
struct HLDecomposition
{
	vector<int> g[M];
	int dep[M],fa[M],sz[M],son[M],top[M];
	int dfn[M],id[M],ndfn;
	void dfs1(int u,int f,int d)
	{
		dep[u]=d; sz[u]=1; fa[u]=f; son[u]=-1;
		for(int v:g[u])
		{
			if(v==f) continue;
			dfs1(v,u,d+1);
			sz[u]+=sz[v];
			if(son[u]==-1||sz[son[u]]<sz[v])
				son[u]=v;
		}
	}
	void dfs2(int u,int t)
	{
		dfn[u]=++ndfn; id[ndfn]=u; top[u]=t;
		segt.update(ndfn,ndfn,val[u]);
		if(son[u]!=-1) dfs2(son[u],t);
		for(int v:g[u])
		{
			if(v==fa[u]||v==son[u]) continue;
			dfs2(v,v);
		}
	}
	void init()
	{
		dfs1(root,-1,0);
		ndfn=0;
		dfs2(root,root);
	}
	void updnode(int a,LL v)
	{
		segt.update(dfn[a],dfn[a],v);
	}
	void updpath(int a,int b,LL v)
	{
		while(top[a]!=top[b])
		{
			if(dep[top[a]]<dep[top[b]]) swap(a,b);
			segt.update(dfn[top[a]],dfn[a],v);
			a=fa[top[a]];
		}
		if(dep[a]>dep[b]) swap(a,b);
		segt.update(dfn[a],dfn[b],v);
	}
	LL qpath(int a,int b)
	{
		LL ans=0;
		while(top[a]!=top[b])
		{
			if(dep[top[a]]<dep[top[b]]) swap(a,b);
			ans+=segt.query(dfn[top[a]],dfn[a]);
			a=fa[top[a]];
		}
		if(dep[a]>dep[b]) swap(a,b);
		ans+=segt.query(dfn[a],dfn[b]);
		return ans;
	}
	void updsubt(int a,LL v)
	{
		segt.update(dfn[a],dfn[a]+sz[a]-1,v);
	}
	LL qsubt(int a)
	{
		return segt.query(dfn[a],dfn[a]+sz[a]-1);
	}
}hld;

int main()
{
	//freopen("P3384.in","r",stdin);
	scanf("%d%d%d%lld",&n,&m,&root,&mo);
	int u,v,w;
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		hld.g[u].push_back(v);
		hld.g[v].push_back(u);
	}
	hld.init();
	int con;
	for(int i=0;i<m;i++)
	{
		scanf("%d",&con);
		if(con==1)
		{
			scanf("%d%d%d",&u,&v,&w);
			hld.updpath(u,v,w);
		}
		else if(con==2)
		{
			scanf("%d%d",&u,&v);
			printf("%lld\n",hld.qpath(u,v)%mo);
		}
		else if(con==3)
		{
			scanf("%d%d",&u,&w);
			hld.updsubt(u,w);
		}
		else
		{
			scanf("%d",&u);
			printf("%lld\n",hld.qsubt(u)%mo);
		}
	}
	return 0;
}