#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int M=505;

int s1[M],s2[M]; // s1[1,n] s2[1,m]
int n,m;
int dp[M]; // end at s2[j] the longest lcis
int pre[M][M];

int lcis()
{
	memset(dp,0,sizeof(dp));
	
	for(int i=1;i<=n;i++)
	{
		int p=-1,mx=0;
		for(int j=1;j<=m;j++)
		{
			// dp[i][j] = dp[i-1][j]
			pre[i][j]=pre[i-1][j];
			if(s1[i]==s2[j]&&dp[j]<mx+1)
			{
				dp[j]=mx+1;
				pre[i][j]=p;
			}
			if(s2[j]<s1[i]&&mx<dp[j])
			{
				mx=dp[j];
				p=j;
			}
		}
	}
	int ans=0,p=-1;
	for(int j=1;j<=m;j++)
	{
		if(ans<dp[j])
		{
			ans=dp[j];
			p=j;
		}
	}
	printf("%d\n",ans);
	vector<int> an;
	for(int i=1;i<=ans;i++)
	{
		an.push_back(s2[p]);
		p=pre[n][p];
		n--;
	}
	for(int i=ans-1;i>=0;i--)
		printf("%d%c",an[i],i?' ':'\n');
	return ans;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&s1[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&s2[i]);
	lcis();
	return 0;
}