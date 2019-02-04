typedef long long LL;


// n,m <=1e6
const int M=1e6+5;
const int MOD=1e9+7;
LL inv[M],fa[M],ifa[M];
void init()
{
	fa[0]=ifa[0]=1;
	inv[1]=fa[1]=ifa[1]=1;
    for(int i=2;i<M;i++)
    {
    	fa[i]=fa[i-1]*i%MOD;
    	inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
    	ifa[i]=inv[i]*ifa[i-1]%MOD;
    }
}
LL C1(LL n,LL m)
{
	if(m>n) return 0;
	return fa[n]*ifa[m]%MOD*ifa[n-m]%MOD;
}


//m<=1e5 
//MOD is prime
LL qp(LL a,LL n)
{
	LL ans=1;
	while(n)
	{
		if(n&1) ans=ans*a%MOD;
		a=a*a%MOD;
		n>>=1;
	}
	return ans;
}
LL C2(LL n,LL m)
{
	if(m>n) return 0;
	LL ans=1;
	for(int i=1;i<=m;i++)
		ans=ans*(n-i+1)%MOD*qp(i,MOD-2)%MOD;
	return ans;
}