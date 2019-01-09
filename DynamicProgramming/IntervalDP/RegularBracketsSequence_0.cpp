#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int M=105;
const int INF=0x3f3f3f3f;
char s[M],n;
int dp[M][M];

inline bool match(char a,char b)
{
	return a=='('&&b==')' || a=='['&&b==']'; 
}

void getdp()
{
	for(int i=0;i<n;i++)
		dp[i+1][i]=0,dp[i][i]=1;
	for(int l=2;l<=n;l++)
		for(int i=0,j;(j=i+l-1)<n;i++)
		{
			dp[i][j]=INF;
			if(match(s[i],s[j]))
				dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
			for(int k=i;k<j;k++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
		}
}

void print(int l,int r)
{
	if(l>r) return;
	if(l==r)
	{
		if(s[l]=='('||s[l]==')') printf("()");
		else printf("[]");
		return;
	}
	int ans=dp[l][r];
	if(match(s[l],s[r])&&ans==dp[l+1][r-1])
	{
		printf("%c",s[l]);
		print(l+1,r-1);
		printf("%c",s[r]);
		return;
	}
	for(int k=l;k<r;k++)
		if(ans==dp[l][k]+dp[k+1][r])
		{
			print(l,k); print(k+1,r);
			return;
		}
}

int main()
{
	scanf("%s",s);
	n=strlen(s);
	getdp();
	print(0,n-1);
	printf("\n");
	
	return 0;
}