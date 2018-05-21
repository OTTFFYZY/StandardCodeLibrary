vector<int> grayCode(int n)
{
    int mask=1,now=0;
    vector<int> ans={0};
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<mask;j++)
            ans.push_back(mask^ans[mask-1-j]);
        mask<<=1;
    }
    return ans;
}

vector<int> grayCode(int n)
{
    int mask=1<<n,now=0;
    vector<int> ans;
    for(int i=0;i<mask;i++)
    {
        ans.push_back(now);
        if(i&1)
            now^=(now&-now)<<1;
        else now^=1;
    }
    return ans;
}