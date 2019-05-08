int n;
vector<int> col;
int dfs(int u,vector<vector<int>>& g)
{
    if(col[u]) return col[u]==2;
    col[u]=1;
    for(int v:g[u])
        if(!dfs(v,g)) return 0;
    col[u]=2;
    return 1;
}
vector<int> loopUnreachableVertices(vector<vector<int>>& g) {
    n=g.size();
    col.assign(n,0);
    vector<int> ans;
    for(int i=0;i<n;i++)
        if(dfs(i,g)) ans.push_back(i);
    return ans;
}