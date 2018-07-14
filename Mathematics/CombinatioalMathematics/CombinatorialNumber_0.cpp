typedef long long LL;
const int M=20;
LL fac[M];
void init()
{
	fac[0]=1;
	for(int i=1;i<M;i++)
		fac[i]=fac[i-1]*i;
}
int C(int n,int m) //O(1)
{
	return fac[n]/fac[m]/fac[n-m];
}

int C_2(int n,int m) //O(n)
{
	int ans=1;
	for(int i=1;i<=m;i++)
		ans=ans*(n-i+1)/i;
	return ans;
}