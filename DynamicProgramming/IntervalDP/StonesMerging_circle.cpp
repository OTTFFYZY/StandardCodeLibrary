#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=105;
const int INF=0x3f3f3f3f;
int a[M],sum[M];
int dp0[M][M];
int dp1[M][M];
int n;

int getsum(int l,int r)
{
	if(l<r) return sum[r]-sum[l-1];
	return sum[r]+sum[n]-sum[l-1];
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	memset(dp0,INF,sizeof(dp0));
	memset(dp1,0,sizeof(dp1));
	for(int i=1;i<=n;i++)
		dp0[i][i]=dp1[i][i]=0;
	for(int len=2;len<=n;len++)
	{
		for(int l=1,r;l<=n;l++)
		{
			r=(l+len-1-1+n)%n+1;
			int tmp0=INF,tmp1=0;
			for(int k=l;k!=r;k=k%n+1)
			{
				tmp0=min(tmp0,dp0[l][k]+dp0[k%n+1][r]);
				tmp1=max(tmp1,dp1[l][k]+dp1[k%n+1][r]);
			}
			dp0[l][r]=tmp0+getsum(l,r);
			dp1[l][r]=tmp1+getsum(l,r);
		}
	}
	int ans0=INF,ans1=0;
	if(n==1) ans0=ans1=0;
	else
	{
		for(int l=1;l<=n;l++)
		{
			int r=(l==1 ? n : l-1);
			ans0=min(ans0,dp0[l][r]);
			ans1=max(ans1,dp1[l][r]);
		}
	}
	printf("%d\n%d\n",ans0,ans1);
	return 0;
}