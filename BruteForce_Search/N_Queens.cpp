class Solution {
public:
    vector<vector<string> > ans;
    vector<string> tmp;
    void dfs(int dep,int col,int s1,int s2,int n)
    {
        if(dep==n)
        {
            ans.push_back(tmp);
            return;
        }
        s1>>=1; s2<<=1;
        for(int i=0;i<n;i++)
        {
            if(col&(1<<i)||s1&(1<<i)||s2&(1<<i)) continue;
            tmp[dep][i]='Q';
            dfs(dep+1,col|(1<<i),s1|(1<<i),s2|(1<<i),n);
            tmp[dep][i]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        tmp.assign(n,string(n,'.'));
        dfs(0,0,0,0,n);
        return ans;
    }
};