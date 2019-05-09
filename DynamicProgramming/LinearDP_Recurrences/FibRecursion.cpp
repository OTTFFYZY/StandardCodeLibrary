#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=123456;
const int MO=100003;

inline void add(int &x,int y)
{
	x+=y;
	if(x>=MO) x-=MO;
}
inline void sub(int &x,int y)
{
	x-=y;
	if(x<0) x+=MO;
}

int dp[M];

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	memset(dp,0,sizeof(dp));
	dp[1]=1; sub(dp[k+1],1);
	int presum=0;
	for(int i=1;i<=n;i++)
	{
		add(presum,dp[i]);
		dp[i]=presum;
		add(dp[i+1],dp[i]);
		sub(dp[i+k+1],dp[i]);
	}
	printf("%d\n",dp[n]);
	return 0;
}