const int M=1e4+5;
int isp[M],pri[M],pre[M],npri=0;
void get_pri()
{
    for(int i=2;i<M;i++)
    {
        if(!isp[i])
        {
            pre[i]=i;
            //pre[i]=npri;
            pri[npri++]=i;
        }
        for(int j=0;j<npri&&pri[j]<M/i;j++)
        {
            isp[i*pri[j]]=1;
            //pre[i*pri[j]]=j;
            pre[i*pri[j]]=pri[j];
            if(i%pri[j]==0) break;
        }
    }
}
vector<int> get_factor(int nu)
{
    vector<int> fa;
    if(nu==1) return fa; // fa.push_back(1);
    while(nu!=1)
    {
        fa.push_back(pre[nu]);
        nu/=pre[nu];
    }
    return fa;
}

/* O(nlogn)
void getpri()
{
	for(int i=2;i<M;i++)    //i*i <=n <= INT_MAX
		if(!isp[i])
        {
            pre[i]=npri;
            pri[npri]=i;
            for(int j=i*2;j<M;j+=i)
            {
                isp[j]=1;
                pre[j]=npri;
            }
            npri++;
        }
}
*/
/*
int fac[M];
void get_factor(int n)
{
	while(n!=1)
    {
        fac[pre[n]]++;
        n/=pri[pre[n]];
    }
}
*/