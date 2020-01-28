#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;
const int M=1e4+5;
const int INF=0x3f3f3f3f;

vector<PII> g[M];

int vis[M],dis[M];
bool dfs_spfa(int u)
{
	vis[u]=1;
	for(auto e:g[u])
	{
		int v=e.first;
		int w=e.second;
		if(dis[v]>dis[u]+w)
		{
			dis[v]=dis[u]+w;
			if(vis[v]||!dfs_spfa(v)) return false;
		}
	}
	vis[u]=0;
	return true;
}

bool hasNegtiveLoop(int st)
{
	memset(vis,0,sizeof(vis));
	memset(dis,INF,sizeof(dis));
	return dfs_spfa(st);
}

int main()
{
	return 0;
}