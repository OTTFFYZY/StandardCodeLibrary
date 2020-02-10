#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

const int MV=1005;
vector<int> g[MV];
// id from 0
// ids in left set and which in right could be same
// only left to right edges in g 

int nvl; //vertex in the left side

int vis[MV],match[MV];
//vis    in alternating path
//match[i] result right i match left match[i]

bool dfs(int u)
{
	for(int v:g[u])
	{
		if(vis[v]) continue;
		vis[v]=1;
		if(match[v]==-1||dfs(match[v]))
		{
			match[v]=u;
			return true;
		}
	}
	return false;
}

int hungarian()
{
	int ans=0;
	memset(match,-1,sizeof(match));
	for(int i=0;i<nvl;i++)
	{
		memset(vis,0,sizeof(vis));
		ans+=dfs(i);
	}
	return ans;
}

int main()
{
	return 0;
}