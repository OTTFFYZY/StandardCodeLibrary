const int M=1e3+5;
int dp[M];
int w[M],v[M];
int V,n;
void zeroOnePack(int v,int w) //O(V)
{
	for(int i=V;i>=v;i--)
		dp[i]=max(dp[i],dp[i-v]+w);
}
int solve()
{
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
		zeroOnePack(v[i],w[i]);
	return dp[V];
}

const int INF=0x3f3f3f3f;
int solve2()
{
	memset(dp,-INF,sizeof(dp));
	dp[0]=0;
	for(int i=0;i<n;i++)
		zeroOnePack(v[i],w[i]);
	return dp[V]>=0?dp[V]:-1;
}