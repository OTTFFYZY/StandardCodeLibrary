vector<vector<int> > g;
vector<vector<int> > ans;
vector<int> mark;
vector<int> dep;
void dfs(int u,int fa,int d)
{
    dep[u]=d;
    for(int v:g[u])
    {
        if(v==fa) continue;
        if(!dep[v])
        {
            dfs(v,u,d+1);
            if(!mark[v])
                ans.push_back({u,v});
            mark[u]+=mark[v];
        }
        else if(dep[v]<dep[u])
        {
            mark[v]--;
            mark[u]++;
        }
    }
}