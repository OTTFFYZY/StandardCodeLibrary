const int M=1e4+5;
int isp[M],pri[M],pre[M],npri=0;
void get_pri()
{
    for(int i=2;i<M;i++)
    {
        if(!isp[i])
        {
            pre[i]=npri;
            pri[npri++]=i;
        }
        for(int j=0;j<npri&&pri[j]<M/i;j++)
        {
            isp[i*pri[j]]=1;
            pre[i*pri[j]]=j;
            if(i%pri[j]==0) break;
        }
    }
}

/* O(nloglogn)
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
int fac[M];
void get_factor(int n)
{
	while(n!=1)
    {
        fac[pre[n]]++;
        n/=pri[pre[n]];
    }
}