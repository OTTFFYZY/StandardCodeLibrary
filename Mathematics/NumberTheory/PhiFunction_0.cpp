// sqrt(n)

int phi(int n)
{
	int ans=n;
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
		{
			ans=ans/i*(i-1);
			while(n%i==0) n/=i;
		}
	if(n!=1) ans=ans/n*(n-1);
	return ans;
}


// sqrt(n)/log(n)
const int M=1e5+5; // sqrt(N)
int isp[M],pri[M],npri;
void init()
{
	npri=0;
	for(int i=2;i<M;i++)
		if(!isp[i])
		{
			pri[npri++]=i;
			for(int j=i*i;j<M;j+=i)
				isp[j]=1;
		}
}
int phi2(int n)
{
	int ans=n;
	for(int i=0;pri[i]*pri[i]<=n;i++)
		if(n%pri[i]==0)
		{
			ans=ans/pri[i]*(pri[i]-1);
			while(n%pri[i]==0) n/=pri[i];
		}
	if(n!=1) ans=ans/n*(n-1);
	return ans;
}