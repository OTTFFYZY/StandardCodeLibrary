#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

const int MV=1e3+5;
vector<int> g[MV];
int nvl; //vertex in the left side

int vis[MV],match[MV];
//vis    in alternating path
//match  result

bool dfs(int u)
{
	for(int v:g[u])
	{
		if(vis[v]) continue;
		vis[v]=1;
		if(match[v]==-1||dfs(v))
		{
			match[v]=u;
			match[u]=v;
			return 1;
		}
	}
	return 0;
}

int hungarian()
{
	int ans=0;
	memset(match,-1,sizeof(match));
	for(int i=0;i<nvl;i++)
		if(match[i]==-1)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ans++;
		}
	return ans;
}

int main()
{
	return 0;
}