#include <iostream>
using namespace std;

const int M=305;
const int INF=0x3f3f3f3f;
int stone[M],n; // i-th pile has stone[i] stones
int dp[M][M];

int StonesMerging() // O(n^3)
{
	//memset(dp,0,sizeof(dp)); //dp[i][i]=0;
	for(int i=1;i<=n;i++)
		stone[i]+=stone[i-1];
	for(int i=2;i<=n;i++)
	{
		for(int st=1,ed;(ed=st+i-1)<=n;st++)
		{
			dp[st][ed]=INF;
			for(int k=st;k<ed;k++)
				dp[st][ed]=min(dp[st][ed],
							   dp[st][k]+dp[k+1][ed]+stone[ed]-stone[st-1]);
		}
	}
	return dp[1][n];
}

int main()
{
	//n=4; stone[1]=stone[2]=stone[3]=stone[4]=25;
	n=5; stone[1]=4; stone[2]=1; stone[3]=2; stone[4]=1; stone[5]=2;
	cout<< StonesMerging() <<endl;
	return 0;
}