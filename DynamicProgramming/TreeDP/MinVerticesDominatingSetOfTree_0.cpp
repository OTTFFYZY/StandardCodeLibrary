#include <bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f;
const int M=1e5+5;
vector<int> g[M];
int dp[M][3];
// dp[u][0] select u
// dp[u][1] not select u and dominate by son of u
// dp[u][2] not select u and not dominate by son of u

void dfs(int u,int fa)
{
	int ch=g[u].size()-(fa!=-1);
	dp[u][0]=1; dp[u][2]=0;
	if(!ch)
	{
		dp[u][1]=INF;
		return;
	}
	dp[u][1]=0;
	int f=0,diff=INF;
	for(int v:g[u])
	{
		if(v==fa) continue; 
		dfs(v,u);
		dp[u][0]+=min(dp[v][0],min(dp[v][1],dp[v][2]));
		dp[u][2]+=dp[v][1]; 
		if(dp[u][2]>INF) dp[u][2]=INF;
		if(dp[v][0]<=dp[v][1])
		{
			f=1;
			dp[u][1]+=dp[v][0];
		}
		else
		{
			diff=min(diff,dp[u][0]-dp[v][1]);
			dp[u][1]+=dp[v][1];
		}
	}
	if(!f) dp[u][1]+=diff;
}

int min_dom_set(int u)
{
	dfs(u,-1);
	return min(dp[u][0],dp[u][1]);
}

int main()
{
	int n; scanf("%d",&n);
	int u,v;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	printf("%d\n",min_dom_set(1));
	return 0;
}