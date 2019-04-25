int dp[1005][1005][4];
class Solution {
public:
    int MO=1e9+7;
    void add(int &x,int y)
    {
        x+=y;
        if(x>=MO) x-=MO;
    }
    void sub(int &x,int y)
    {
        x-=y;
        if(x<0) x+=MO;
    }
    int countPalindromicSubsequences(string S) {
        int n=S.length();
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            dp[i][i][S[i]-'a']=1;
        for(int len=2;len<=n;len++)
        {
            for(int l=0,r=len-1;r<n;l++,r++)
            {
                for(int i=0;i<4;i++)
                {
                    add(dp[l][r][i],dp[l+1][r][i]);
                    add(dp[l][r][i],dp[l][r-1][i]);
                    sub(dp[l][r][i],dp[l+1][r-1][i]);
                }
                if(S[l]==S[r])
                {
                    int c=S[l]-'a';
                    dp[l][r][c]=2;
                    for(int i=0;i<4;i++)
                        add(dp[l][r][c],dp[l+1][r-1][i]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<4;i++)
            add(ans,dp[0][n-1][i]);
        return ans;
    }
};