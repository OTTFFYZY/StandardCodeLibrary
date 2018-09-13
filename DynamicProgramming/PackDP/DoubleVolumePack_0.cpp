#include <iostream>
using namespace std;

const int M=1e3+5;
int dp[M][M];
int w[M],v1[M],v2[M];
int V1,V2,n;

void doubleVolumePack(int w,int v1,int v2)
{
	for(int i=V1;i>=v1;i--)
		for(int j=v1;j>=v2;j--)
			dp[i][j]=max(dp[i][j],dp[i-v1][j-v2]+w);
}
int solve()
{
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
		doubleVolumePack(w[i],v1[i],v2[i]);
	return dp[V1][V2];
}

int main()
{

	return 0;
}