const int INF=0x3f3f3f3f;
int g[12][12];
int ans,n;
int vis[12];
//void dfs(int u,int dep,int nans,int st) //back to start
void dfs(int u,int dep,int nans)
{
    if(nans+n-dep>=ans) return;
    //if(nans+n-dep+1>=ans) return; //back to start
    if(dep==n)
    {
        //for(int i=0;i<n;i++) cout<<(vis[i]-1)<<" ";
        //cout<<endl; // show path
        ans=min(ans,nans);
        //ans=min(ans,g[u][st]+nans); //back to start
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(vis[i]||(dep&&g[u][i]==INF)) continue;
        vis[i]=dep+1;
        dfs(i,dep+1,nans+(dep?g[u][i]:0));
        //dfs(i,dep+1,nans+(dep?g[u][i]:0),dep?st:i); //back to start
        vis[i]=0;
    }
}
int shortestPathLength(vector<vector<int>>& graph)
{
    n=graph.size();
    memset(g,INF,sizeof(g));
    for(int i=0;i<n;i++)
    {
        for(int j:graph[i])
            g[i][j]=1;
    }
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(g[i][k]<INF&&g[k][j]<INF)
                    g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    ans=INF;
    memset(vis,0,sizeof(vis));
    dfs(-1,0,0);
    //dfs(-1,0,0,0); //back to start
    return ans;
}