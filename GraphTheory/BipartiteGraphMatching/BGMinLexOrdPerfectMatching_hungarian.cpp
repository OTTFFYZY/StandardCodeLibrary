#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

const int M=10005;
vector<int> g[M];

int vis[M],matchl[M],matchr[M];
int n;

int mi;
bool dfs(int u)
{
	if(u<mi) return false;
	for(int v:g[u])
	{
		if(vis[v]) continue;
		vis[v]=1;
		if(matchl[v]==-1||dfs(matchl[v]))
		{
			matchl[v]=u;
			matchr[u]=v;
			return true;
		}
	}
	return false;
}

int max_match()
{
	int ans=0;
	mi=-1;
	memset(matchl,-1,sizeof(matchl));
	for(int i=0;i<n;i++)
	{
		memset(vis,0,sizeof(vis));
		ans+=dfs(i);
	}
	return ans;
}

void fix()
{
	for(int u=0;u<n;u++)
	{
		mi=u;
		int cr=matchr[u];
		matchl[cr]=-1;
		memset(vis,0,sizeof(vis));
		dfs(u);
	}
}

bool minPerfectMatching()
{
	if(max_match()<n) 
		return false; // no perfect match
	fix();
	return true;
}

int main()
{
	
	return 0;
}