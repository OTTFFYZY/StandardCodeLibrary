int INF=1e6+5;
int dp[33][33][33];
int sum[33];
int n,p,k;
int getdp(int l,int r,int p) // [l,r] -> p piles
{
    if(r-l+1==p) return 0;
    if(r-l+1<p) return INF;
    if(dp[l][r][p]!=-1) return dp[l][r][p];
    int &ans=dp[l][r][p]=INF;
    if(p==1)
        ans=getdp(l,r,k)+sum[r+1]-sum[l];
    else
        for(int i=l;i<r;i++)
            ans=min(ans,getdp(l,i,p-1)+getdp(i+1,r,1));
    return ans;
}
int mergeStones(vector<int>& stones, int K) 
{
    n=stones.size(),k=K;
    if(n==1) return 0;
    if((n-1)%(k-1)) return -1;
    memset(sum,0,sizeof(sum));
    for(int i=0;i<n;i++)
        sum[i+1]=sum[i]+stones[i];
    memset(dp,-1,sizeof(dp));
    return getdp(0,n-1,1);
}