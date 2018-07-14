const int M=1e5+5;
int phi[M];

void init_phi()
{
	phi[1]=1;
	for(int i=2;i<M;i++)
		if(!phi[i])
			for(int j=i;j<M;j+=i)
			{
				if(!phi[j]) phi[j]=j;
				phi[j]=phi[j]/i*(i-1);
			}
}