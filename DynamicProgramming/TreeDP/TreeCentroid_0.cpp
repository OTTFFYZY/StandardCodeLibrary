#include <iostream>
#include <vector>
using namespace std;

const int M=1e5+5;
vector<int> g[M];
int nv;
int dp[M];
int cen,mint;

void dfs(int u,int fa)
{
	int nma=0;
	for(int v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u,fa);
		nma=max(nma,dp[v]);
	}
	dp[u]++;
	nma=max(nma,nv-dp[u]);
	if(nma<mint)
	{
		mint=nma;
		cen=u;
	}
	if(fa!=-1) dp[fa]+=dp[u];
}

int treeCentroid()
{
	memset(dp,0,sizeof(dp));
	mint=nv;
	dfs(0,-1);
	return cen;
}

int main()
{
	return 0;
}