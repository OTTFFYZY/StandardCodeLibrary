#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int M=505;
char s[M];
int dp[M][M];


int main()
{
	int n; scanf("%d%s",&n,s);
	//memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
		dp[i][i]=1;
	for(int i=0;i<n-1;i++)
	{
		if(s[i]==s[i+1]) dp[i][i+1]=1;
		else dp[i][i+1]=2;
	}
	for(int i=3;i<=n;i++)
	{
		for(int l=0,r;(r=l+i-1)<n;l++)
		{
			dp[l][r]=min(dp[l][r-1],dp[l+1][r])+1;
			for(int k=l+1;k<=r;k++)
				if(s[l]==s[k])
					dp[l][r]=min(dp[l][r],dp[l+1][k]+dp[k+1][r]);
		}
	}
	printf("%d\n",dp[0][n-1]);
	return 0;
}