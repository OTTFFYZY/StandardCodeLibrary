typedef long long LL;


// n,m <=1e6
const int M=1e6+5;
const int MOD=1e9+7;
inline int add(int x,int y)
{
	x+=y;
	if(x>=MO) x-=MO;
	return x;
}
inline int sub(int x,int y)
{
	x-=y;
	if(x<0) x+=MO;
	return x;
}
inline int mul(int x,int y)
{
	return 1LL*x*y%MO;
}
inline void addv(int &x,int y)
{
	x+=y;
	if(x>=MO) x-=MO;
}
inline void subv(int &x,int y)
{
	x-=y;
	if(x<0) x+=MO;
}
inline void mulv(int &x,int y)
{
	x=1LL*x*y%MO;
}
 
int inv[M],fa[M],ifa[M];
void init()
{
	fa[0]=ifa[0]=1;
	inv[1]=fa[1]=ifa[1]=1;
    for(int i=2;i<M;i++)
    {
    	fa[i]=mul(fa[i-1],i);
    	inv[i]=mul(MO-MO/i,inv[MO%i]);
    	ifa[i]=mul(inv[i],ifa[i-1]);
    }
}
 
int C(int n,int m)
{
	if(n<m) return 0;
	return mul(mul(fa[n],ifa[m]),ifa[n-m]);
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