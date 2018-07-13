const int M=1e5;

int fa[15][2]; //2*3*5*7*11*13*17*19=9699690
int get_fac(int n,int fa[15][2])
{
	int k=0;
	for(int i=2;i<=n/i;i++)
		if(n%i==0)
		{
			fa[k][0]=i; fa[k][1]=0;
			while(n%i==0)
			{
				fa[k][1]++;
				n/=i;
			}
			k++;
		}
	if(n!=1)
	{
		fa[k][0]=n;
		fa[k++][1]=1;
	}
	return k;
}

// use prime table
int isp[M],pri[M],npri=0;
void getpri1()
{
	//isp[0]=isp[1]=1;
	for(int i=2;i*i<M;i++)    //i*i <=n <= INT_MAX
		if(!isp[i])
			for(int j=i*i;j<M;j+=i) 
				isp[j]=1;
	for(int i=2;i<M;i++)
		if(!isp[i]) pri[npri++]=i;
}

int get_fac2(int n,int fa[15][2])
{
	int k=0;
	for(int i=0;pri[i]<=n/pri[i]&&i<npri;i++)
		if(n%pri[i]==0)
		{
			fa[k][0]=pri[i]; fa[k][1]=0;
			while(n%pri[i]==0)
			{
				fa[k][1]++;
				n/=pri[i];
			}
			k++;
		}
	if(n!=1)
	{
		fa[k][0]=n;
		fa[k++][1]=1;
	}
	return k;
}
