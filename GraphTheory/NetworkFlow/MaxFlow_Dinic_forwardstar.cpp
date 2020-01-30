#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MV=205;
const int ME=1005;
const int INF=0x3f3f3f3f;

int n,m;

struct MaxFlow
{
	struct Edge
	{
		int u,v,nxt;
		int cp,rm;
		Edge(int u=0,int v=0,int nxt=0,int cp=0,int rm=0)
			:u(u),v(v),nxt(nxt),cp(cp),rm(rm){}
	}edges[ME*2];
	int head[MV],nne;
	int nv;
	void init(int n) // id of vertexes [0,n-1]
	{
		nv=n;
		nne=0;
		memset(head,-1,sizeof(head));
	}
	void addedge(int u,int v,int cp)
	{
		edges[nne]=Edge(u,v,head[u],cp,cp);
		head[u]=nne++;
		edges[nne]=Edge(v,u,head[v]);
		head[v]=nne++;
	}
	int sr,sk;
	int d[MV];
	queue<int> qu;
	bool bfs()
	{
		while(!qu.empty()) qu.pop();
		memset(d,INF,sizeof(d));
		d[sr]=0;
		qu.push(sr);
		while(!qu.empty())
		{
			int u=qu.front(); qu.pop();
			if(u==sk) return true;
			for(int e=head[u];e!=-1;e=edges[e].nxt)
			{
				int v=edges[e].v;
				if(d[v]==INF&&edges[e].rm>0)
				{
					d[v]=d[u]+1;
					qu.push(v);
				}
			}
		}
		return false;
	}
	int cur[MV];
	int dfs(int u,int mf)
	{
		if(u==sk||!mf) return mf;
		int nf=0,fl;
		for(int &e=cur[u];e!=-1;e=edges[e].nxt)
		{
			int v=edges[e].v;
			if(d[v]==d[u]+1&&(fl=dfs(v,min(mf,edges[e].rm))))
			{
				edges[e].rm-=fl;
				edges[e^1].rm+=fl;
				nf+=fl;
				mf-=fl;
				if(!mf) break;
			}
		}
		return nf;
	}
	int maxflow()
	{
		int mf=0;
		while(bfs())
		{
			for(int i=0;i<nv;i++)
				cur[i]=head[i];
			mf+=dfs(sr,INF);
		}
		return mf;
	}
}mf;