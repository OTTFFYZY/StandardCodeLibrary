const int M=1e3+5;
int dp[M];
int w[M],v[M];
int V,n;
void completePack(int v,int w) //O(V)
{
	for(int i=v;i<=V;i++)
		dp[i]=max(dp[i],dp[i-v]+w);
}
int solve()
{
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
		completePack(v[i],w[i]);
	return dp[V];
}