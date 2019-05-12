#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int M=1005;
int dp[M][M];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			scanf("%d",&dp[i][j]);
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
			dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+dp[i][j];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[n][i]);
	printf("%d\n",ans);
	return 0;
}