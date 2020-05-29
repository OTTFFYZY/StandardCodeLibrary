const int M=505;
int C[M][M];
void init_C()
{
	for(int i=0;i<M;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
}

int Cn[M];
void init_C(int n)
{
	Cn[0]=1;
	for(int i=1;i<=n;i++)
		Cn[i]=C[i-1]*(n-i+1)/i;
}