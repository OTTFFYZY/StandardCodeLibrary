class Solution {
public:
    vector<int> d,w;
    vector<vector<int> > dp;
    int md;
    int dfs(int dep,int lim)
    {
        if(dp[lim][dep]!=-1) return dp[lim][dep];
        if(dep==0)
        {
            if(lim)
            {
                dp[lim][dep]=0;
                for(int i:d)
                    if(i>w[dep]) break;
                    else dp[lim][dep]++;
            }
            else
                dp[lim][dep]=d.size();
            return dp[lim][dep];
        }
        dp[lim][dep]=0;
        if(lim)
        {
            for(int i:d)
                if(i>w[dep]) break;
                else if(i==w[dep])
                    dp[lim][dep]+=dfs(dep-1,1);
                else
                    dp[lim][dep]+=dfs(dep-1,0);
        }
        else
            dp[lim][dep]=d.size()*dfs(dep-1,0);
        //cout<<lim<<" "<<dep<<" "<<dp[lim][dep]<<endl;
        return dp[lim][dep];
    }
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        for(string s:D)
            d.push_back(s[0]-'0');
        int n=N;
        while(N)
        {
            w.push_back(N%10);
            N/=10;
        }
        md=w.size();
        dp.assign(2,vector<int>(md,-1));
        int ans=dfs(md-1,1);
        int NN=N=9;
        while(N<n)
        {
            //cout<<N<<endl;
            w.clear();
            while(N)
            {
                w.push_back(N%10);
                N/=10;
            }
            md=w.size();
            dp.assign(2,vector<int>(md,-1));
            ans+=dfs(md-1,1);
            N=NN=NN*10+9;
        }
        return ans;
    }
};