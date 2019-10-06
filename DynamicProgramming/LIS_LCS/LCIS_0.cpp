#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=5005;

char s1[M],s2[M]; // s1[1,n] s2[1,m]
int n,m;
int dp[M]; // end at s2[j] the longest lcis

int lcis()
{
	memset(dp,0,sizeof(dp));
	
	for(int i=1;i<=n;i++)
	{
		int mx=0;
		for(int j=1;j<=m;j++)
		{
			// dp[i][j] = dp[i-1][j]
			if(s1[i]==s2[j]) dp[j]=max(dp[j],mx+1);
			if(s1[j]<s1[i]) mx=max(mx,dp[j]);
		}
	}
	int ans=0;
	for(int j=1;j<=m;j++)
		ans=max(ans,dp[j]);
	return ans;
}

int main()
{

	return 0;
}