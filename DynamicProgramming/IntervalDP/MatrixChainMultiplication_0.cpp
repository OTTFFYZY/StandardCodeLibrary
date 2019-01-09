#include <iostream>
using namespace std;

const int M=305;
const int INF=0x3f3f3f3f;
int si[M],n;
// Ai (si[i],si[i+1])
int dp[M][M];

int MCM()
{
	//memset(dp,0,sizeof(dp));
	for(int i=2;i<=n;i++)
	{
		for(int st=0,ed;(ed=st+i-1)<n;st++)
		{
			dp[st][ed]=INF;
			for(int k=st;k<ed;k++)
				dp[st][ed]=min(dp[st][ed],
							   dp[st][k]+dp[k+1][ed]+si[st]*si[k+1]*si[ed+1]);
		}
	}
	return dp[0][n-1];
}

int main()
{
	n=3;
	si[0]=5; si[1]=4; si[2]=3; si[3]=2;
	cout<< MCM() <<endl;
	return 0;
}