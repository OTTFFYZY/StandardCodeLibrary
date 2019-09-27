#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const int MV=1005;
const int ME=1005;
const int INF=0x3f3f3f3f;
// O(VlogV+E+kV)

struct DegreeConstrainedMST
{
	struct Edge
	{
		int u,v,w;
		Edge(int u=0,int v=0,int w=0)
			:u(u),v(v),w(w){}
		bool operator<(const Edge &B) const
		{
			return w<B.w;
		}
	};

	struct DSU
	{
		vector<int> uf,rank;
		void init(int n)
		{
			for(int i=0;i<n;i++)
				uf.push_back(i);
			rank.assign(n,0);
		}
		int find(int x)
		{
			return x==uf[x]?x:uf[x]=find(uf[x]);
		}
		void merge(int x,int y)
		{
			x=find(x); y=find(y);
			if(x==y) return;
			if(rank[x]<rank[y])
				swap(x,y);
			if(rank[x]==rank[y])
				rank[x]++;
			uf[y]=x;
		}
	};

	int n,m;
	int v0,mink,k;
	int cnt,totw;
	
	int g[MV][MV];
	int inmst[MV][MV];
	vector<Edge> edges;
	DSU dsu;
	
	void init(int n,int m,int v0,int k)
	{
		edges.clear();
		memset(g,INF,sizeof(g));
		totw=0;
	}
	void add_edge(int u,int v,int w)
	{
		if(w>=g[u][v]) return;
		g[u][v]=g[v][u]=w;
		edges.emplace_back(u,v,w);
	}
	void kruskal()
	{
		sort(edges.begin(),edges.end());
		cnt=0;
		dsu.init(n);
		for(Edge e:edges)
		{
			if(e.u==v0 || e.v==v0) continue;
			int u=dsu.find(e.u),v=dsu.find(e.v);
			if(u==v) continue;
			cnt++;
			dsu.merge(u,v);
			totw+=e.w;
			inmst[e.u][e.v]=inmst[e.v][e.u]=1;
		}
		//return cnt;
	}
	int mi[MV],mie[MV];
	void mindegree_mst()
	{
		memset(mi,INF,sizeof(mi));
		for(int v=0;v<n;v++)
		{
			if(v==v0) continue;
			if(g[v0][v]==INF) continue;
			int t=dsu.find(v);
			if(g[v0][v]<mi[t])
			{
				mi[t]=g[v0][v];
				mie[t]=v;
			}
		}
		mink=0;
		for(int i=0;i<n;i++)
			if(mi[i]!=INF)
			{
				cnt++;
				inmst[v0][mie[i]]=inmst[mie[i]][v0]=1;
				totw+=mi[i];
				mink++;
			}
	}
	Edge dp[MV];
	void dfs(int u,int fa)
	{
		for(int v=0;v<n;v++)
		{
			if(v==v0||v==fa||!inmst[u][v])
				continue;
			if(dp[v].w==-1)
			{
				if(g[u][v]<dp[u].w) dp[v]=dp[u];
				else dp[v].u=u,dp[v].v=v,dp[v].w=g[u][v];
			}
			dfs(v,u);
		}
	}
	bool dc_mst()
	{
		kruskal();
		mindegree_mst();
		// no mst
		if(cnt+1<n) return false;
		if(mink>k) return false;

		for(int i=mink+1;i<=k;i++)
		{
			memset(dp,-1,sizeof(dp));
			for(int i=0;i<n;i++)
			{
				if(i==v0) continue;
				if(inmst[v0][i])
					dp[i].w=-INF;
			}	
			dfs(v0,-1);
			int t=v0,minn=-INF;
			for(int v=0;v<n;v++)
			{
				if(g[v0][v]!=INF && g[v0][v]-dp[v].w < minn)
				{
					minn=g[v0][v]-dp[v].w;
					t=v;
				}				
			}
			// less than k degree is ok.
			if(minn >= 0) break;
			inmst[v0][t]=inmst[t][v0]=1;
			int x=dp[t].u,y=dp[t].v;
			inmst[x][y]=inmst[y][x]=0;
			totw+=minn;
		}
		return true;
	}
};

int main()
{
	return 0;
}