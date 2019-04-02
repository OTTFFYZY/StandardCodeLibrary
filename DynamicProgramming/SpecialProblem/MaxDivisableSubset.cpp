#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=1005;
int a[M],n;
int dp[M],pre[M];
int ans[M],nans;

void maxDivSubset()
{
	sort(a,a+n);
	memset(pre,-1,sizeof(pre));
	int mx=0,p=-1;
	for(int i=0;i<n;i++)
	{
		dp[i]=1;
		for(int j=0;j<i;j++)
			if(a[i]%a[j]==0 && dp[i]<dp[j]+1)
				dp[i]=dp[j]+1, pre[i]=j;
		if(mx<dp[i])
			mx=dp[i], p=i;
	}
	nans=0;
	for(int i=p;i!=-1;i=pre[i])
		ans[nans++]=a[i];
}

int main()
{
	return 0;
}