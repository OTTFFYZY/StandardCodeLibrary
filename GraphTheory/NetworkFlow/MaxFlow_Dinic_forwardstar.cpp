#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

const int MV=505;
const int ME=505;
const int INF=0x3f3f3f3f;

struct Edge
{
	int fr,to,nxt;
	int cp,fl;
	Edge(int fr=0,int to=0,int nxt=0,int cp=0,int rm=0)
		:fr(fr),to(to),nxt(nxt),cp(cp),rm(rm){}
}edge[ME*2];
int head[MV],ne,nv;
void init()
{
	memset(head,-1,sizeof(head));
	ne=0;
}
void addedge(int fr,int to,int cp)
{
	edge[ne]=Edge(fr,to,head[fr],cp,cp);
	head[fr]=ne++;
	edge[ne]=Edge(to,fr,head[to]);
	head[to]=ne++;
}

int so,sk; // sourse sink
int d[MV];
queue<int> qu;
int bfs()
{
	while(!qu.empty()) qu.pop();
	memset(d,INF,sizeof(d));
	d[so]=0;
	qu.push(so);
	while(!qu.empty())
	{
		int u=qu.front(); qu.pop();
		if(u==sk) return 1;
		for(int e=head[u];e!=-1;e=edge[e].nxt)
		{
			int v=edge[e].to;
			if(d[v]==INF&&edge[e].rm>0)
			{
				d[v]=d[u]+1;
				qu.push(v);
			}
		}
	}
	return 0;
}
int cur[MV];
int dfs(int u,int mf)
{
	if(u==sk||!mf) return mf;
	int nf=0,fl;
	for(int &e=cur[u];e!=-1;e=edge[e].nxt)
	{
		int v=edge[e].to;
		if(d[v]==d[u]+1&&(fl=dfs(v,min(mf,edge[e].rm))))
		{
			edge[e].rm-=fl;
			edge[e^1].rm+=fl;
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
		mf+=dfs(so,INF);
	}
	return mf;
}