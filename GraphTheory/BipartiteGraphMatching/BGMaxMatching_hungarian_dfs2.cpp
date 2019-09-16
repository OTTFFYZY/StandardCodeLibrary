#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=5005;
vector<int> g[M]; // a->b
int a[M],b[M],match[M],vis[M];

int dfs(int u)
{
	vis[u]=1;
	for(int v:g[u])
	{
		if(vis[v]) continue;
		if(match[v]==-1||dfs(match[v]))
		{
			match[v]=u;
			return 1;
		}
	}
	return 0;
}

int hungarian(int n) // vertices in left set
{
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(match[i]==-1)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ans++;
		}
	}
	return ans;
}

int main()
{
	return 0;
}