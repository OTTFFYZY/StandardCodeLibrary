#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MV=50005;
vector<int> g[MV];
int nv,nvl,ne;
int match[MV],dis[MV],vis[MV];

bool find(int u)
{
	for(int v:g[u])
	{
		if(!vis[v]&&dis[v]==dis[u]+1)
		{
			vis[v]=1;
			if(!match[v]||find(match[v]))
			{
				match[u]=v;
				match[v]=u;
				return 1;
			}
		}
	}
	return 0;
}

queue<int> qu;

bool bfs()
{
	bool f=0;
	while(!qu.empty()) qu.pop();
	memset(dis,0,sizeof(dis));
	for(int i=1;i<=nvl;i++)
		if(!match[i])
		{
			qu.push(i);
			dis[i]=1;
		}
	while(!qu.empty())
	{
		int u=qu.front(); qu.pop();
		for(int v:g[u])
		{
			if(!dis[v])
			{
				dis[v]=dis[u]+1;
				if(match[v])
				{
					dis[match[v]]=dis[v]+1;
					qu.push(match[v])
				}
				else
					f=1;
			}
		}
	}
	return f;
}

int matching()
{
	memset(match,0,sizeof(match));
	int ans=0;
	while(bfs())
	{
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=nvl;i++)
			if(!match[i]&&find(i)) ans++;
	}
	return ans;
}