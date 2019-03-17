#include <stdio.h>
#include <iostream>
using namespace std;

const int M=1005;
int a[M]={3,1,5,2,4,6,3,8};
int dp[M];
int lis(int a[],int n)
{
	int ans=0;
	for(int i=0;i<n;i++)
	{
		dp[i]=1;
		for(int j=0;j<i;j++)
			if(a[i]>a[j])
				dp[i]=max(dp[i],dp[j]+1);
		ans=max(ans,dp[i]);
	}
	return ans;
}

int dp2[M],nlis[M];
int lis2(int a[],int n)
{
	int nn=0;
	for(int i=0;i<n;i++)
	{
		int k=lower_bound(nlis,nlis+nn,a[i])-nlis;
		// unique in lis lower_bound
		// duplicate in lis upper_bound
		if(k==nn) nn++;
		nlis[k]=a[i];
		dp2[i]=k+1;
	}
	return nn;
}

int main()
{

	return 0;
}