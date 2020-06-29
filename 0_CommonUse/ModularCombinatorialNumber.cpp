const int M=1e6+5;
const int MO=1e9+7;
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

int A(int n,int m)
{
	return mul(fa[n],ifa[n-m]);
}