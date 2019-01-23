#include <iostream>
using namespace std;

const int M=305;
const int INF=0x3f3f3f3f;
int stone[M],n; // i-th pile has stone[i] stones
int dp[M][M],p[M][M];

int StonesMerging() // O(n^2)
{
	//memset(dp,0,sizeof(dp)); //dp[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		stone[i]+=stone[i-1];
		p[i][i]=i;
	}
	for(int i=2;i<=n;i++)
	{
		for(int st=1,ed;(ed=st+i-1)<=n;st++)
		{
			int &d=dp[st][ed]=INF,&pp=p[st][ed];
			for(int k=p[st][ed-1];k<=p[st+1][ed];k++)
				if(d>dp[st][k]+dp[k+1][ed]+stone[ed]-stone[st-1])
				{
					d=dp[st][k]+dp[k+1][ed]+stone[ed]-stone[st-1];
					pp=k;
				}
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