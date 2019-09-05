#include <iostream>
using namespace std;

const int M=105;
const int INF=0x3f3f3f3f;


int g[M][M];
int dp[M][M];
int n;

void init()
{
	memset(g,INF,sizeof(g));
	memset(dp,INF,sizeof(dp));
}
void addedge(int u,int v,int w)
{
	g[u][v]=dp[u][v]=w;
}

int minloop()
{
	int ans=INF;
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(g[k][i]==INF||g[j][k]==INF) continue;
				ans=min(ans,dp[i][j]+g[k][i]+g[j][k]);
			}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	}
	return ans;
}

int main()
{
	return 0;
}