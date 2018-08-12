#include <stdio.h>
#include <iostream>
using namespace std;

const int M=1005;
int a[M]={3,1,5,2,4,6,3,8};
int b[M]={3,4,3,5,2,8,2,4};
int dp[M][M];
int lcs(int a[],int n,int b[],int m) //O(nm)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			if(a[i-1]==b[j-1])
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
		}
	return dp[n][m];
}

int main()
{
	cout<<lcs(a,8,b,8)<<endl;
	return 0;
}