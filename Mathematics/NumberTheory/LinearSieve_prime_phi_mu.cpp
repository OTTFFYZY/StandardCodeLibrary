const int M=1e6+5;
int isp[M],pri[M],npri=0;

void get_pri()
{
	for(int i=2;i<M;i++)
	{
		if(!isp[i]) pri[npri++]=i;
		for(int j=0;j<npri&&pri[j]<=(M-1)/i;j++)
		{
			isp[i*pri[j]]=1;
			if(i%pri[j]==0) break;
		}
	}
}

int phi[M];
void get_phi()
{
	phi[1]=1;
	for(int i=2;i<M;i++)
	{
		if(!isp[i])
		{
			pri[npri++]=i;
			phi[i]=i-1;
		}
		for(int j=0;j<npri&&pri[j]<=(M-1)/i;j++)
		{
			isp[i*pri[j]]=1;
			if(i%pri[j]==0)
			{
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			else
				phi[i*pri[j]]=phi[i]*(pri[j]-1);
		}
	}
}

int mu[M];
void get_mu()
{
	mu[1]=1;
	for(int i=2;i<M;i++)
	{
		if(!isp[i])
		{
			pri[npri++]=i;
			mu[i]=-1;
		}
		for(int j=0;j<npri&&pri[j]<=(M-1)/i;j++)
		{
			isp[i*pri[j]]=1;
			if(i%pri[j]==0)
			{
				mu[i*pri[j]]=0;
				break;
			}
			else
				mu[i*pri[j]]=-mu[i];
		}
	}
}