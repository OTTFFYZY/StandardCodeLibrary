const int M=1e3+5;
int dp[M];
int w[M],v[M],n[M];
int V,N;
void zeroOnePack(int v,int w) //O(V)
{
	for(int i=V;i>=v;i--)
		dp[i]=max(dp[i],dp[i-v]+w);
}
void completePack(int v,int w) //O(V)
{
	for(int i=v;i<=V;i++)
		dp[i]=max(dp[i],dp[i-v]+w);
}
void multiplePack(int v,int w,int n)
{
	if(n*v>=V)
	{
		completePack(v,w);
		return;
	}
	for(int k=1;k<n;k*=2)
	{
		zeroOnePack(k*v,k*w);
		n-=k;
	}
	zeroOnePack(n*v,n*w);
}
int solve()
{
	memset(dp,0,sizeof(dp));
	for(int i=0;i<N;i++)
		multiplePack(v[i],w[i],n[i]);
	return dp[V];
}