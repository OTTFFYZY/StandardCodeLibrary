#include <iostream>
#include <string.h>
using namespace std;

const int M=1e5+5;
char s[M];
int dp[3][M];
int lps(char s[])
{
	int l=strlen(s);
	memset(dp,0,sizeof(dp));
	for(int i=0;i<l;i++)
		dp[1][i]=1;
	for(int i=2;i<=l;i++)
		for(int j=0;j<=l-i;j++)
		{
			if(s[j]==s[j+i-1])
				dp[i%3][j]=dp[(i+1)%3][j+1]+2;
			else
				dp[i%3][j]=max(dp[(i+2)%3][j],dp[(i+2)%3][j+1]);
		}
	return dp[l%3][0];
}