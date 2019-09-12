#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MV=205;
const int ME=205;
const int INF=0x3f3f3f3f;

struct MCMF
{
	struct Edge
	{
		int u,v,nxt;
		int cap,cost,flow;
		Edge(int u=0,int v=0,int nxt=0,int cap=0,int cost=0,int flow=0)
			:u(u),v(v),nxt(nxt),cap(cap),cost(cost),flow(flow){}
	}edges[ME*2];
	int head[MV];
	int nne;
	void init()
	{
		memset(head,-1,sizeof(head));
		nne=0;
	}
	void add_edge(int u,int v,int cap,int cost)
	{
		edges[nne]=Edge(u,v,head[u],cap,cost);
		head[u]=nne++;
		edges[nne]=Edge(v,u,head[v],0,-cost);
		head[v]=nne++;
	}

	int dis[MV];
	int vis[MV];
	int pre[MV];
	int src,sink;
	int spfa()
	{
		queue<int> qu;
		qu.push(src);
		memset(dis,INF,sizeof(dis));
		memset(vis,0,sizeof(vis));
		memset(pre,-1,sizeof(pre));
		dis[src]=0;
		vis[src]=1;
		while(!qu.empty())
		{
			int u=qu.front(); qu.pop();
			vis[u]=0;
			for(int e=head[u];~e;e=edges[e].nxt)
			{
				int v=edges[e].v;
				if(edges[e].cap>edges[e].flow 
					&& dis[v]>dis[u]+edges[e].cost)
				{
					dis[v]=dis[u]+edges[e].cost;
					pre[v]=e;
					if(!vis[v])
					{
						vis[v]=1; qu.push(v);
					}
				}
			}
		}
		return ~pre[sink];
	}
	int flow,cost;
	void work(int st,int ed)
	{
		src=st; sink=ed;
		flow=0; cost=0;
		while(spfa())
		{
			int mi=INF;
			for(int e=pre[sink];~e;e=pre[edges[e^1].v])
			{
				if(mi>edges[e].cap-edges[e].flow)
					mi=edges[e].cap-edges[e].flow;
			}
			for(int e=pre[sink];~e;e=pre[edges[e^1].v])
			{
				edges[e].flow+=mi;
				edges[e^1].flow-=mi;
				cost+=edges[e].cost*mi;
			}
		}
	}
};

int main()
{

	return 0;
}