#include <iostream>
#include <vector>
using namespace std;

const int M=1e5+5;
vector<int> g[M];
int nv;
int dp[M],dp2[M];

void dfs(int u,int fa,int gfa)
{
	for(int v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u,fa);
	}
	dp[u]=max(dp[u],dp2[u]+1);
	if(fa!=-1) dp[fa]+=dp[u];
	if(gfa!=-1) dp2[gfa]+=dp[u];
}

int maxVerticesIndependentSet()
{
	memset(dp,0,sizeof(dp));
	memset(dp2,0,sizeof(dp2));
	dfs(0,-1,-1);
	return dp[0];
}

int main()
{
	return 0;
}