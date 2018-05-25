#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;

const int MV=1e5+5;
vector<PII> g[MV];
int nv,ne;
int d[MV],vis[MV],pa[MV];
priority_queue<PII,vector<PII>,greater<PII> > qu;

void addedge(int fr,int to,int dis)
{
	g[fr].emplace_back(to,dis);
}
// single source shortest path  Dijkstra  O(ElogE)
void dijkstra(int st,int ed)
{
	while(!qu.empty()) qu.pop();
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	qu.emplace(0,st);
	d[st]=0;
	while(!qu.empty())
	{
		int nd=qu.top().first,u=qu.top().second; qu.pop();
		if(u==ed) return;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto e:g[u])
		{
			int v=e.first;
			if(d[u]+e.second<d[v])
			{
				d[v]=d[u]+e.second;
				pa[v]=u;
				qu.emplace(d[v],v);
			}
		}
	}
}

stack<int> sta;
void show_path(int st,int ed)
{
	while(!sta.empty()) sta.pop();
	int now=ed;
	while(now!=st)
	{
		sta.push(now);
		now=pa[now];
	}
	sta.push(st);
	while(!sta.empty())
	{
		cout<<sta.top()<<" ";
		sta.pop();
	}
	cout<<endl;
}

int main()
{

	return 0;
}