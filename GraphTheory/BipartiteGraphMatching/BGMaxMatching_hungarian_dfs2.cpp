#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=505;
int g[M][M];

int vis[M],match[M];

bool dfs(int u)
{
	for(int v=0;v<n;v++)
		if(g[u][v]&&!vis[v])
		{
			vis[v]=1;
			if(match[v]==-1||dfs(match[v]))
			{
				match[v]=u;
				return true;
			}
		}
	return false;
}

int max_match()
{
	memset(match,-1,sizeof(match));
	int ans=0;
	for(int i=0;i<n;i++)
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