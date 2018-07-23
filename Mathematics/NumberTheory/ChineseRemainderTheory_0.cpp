typedef long long LL;
void exgcd(LL a,LL b,LL &d,LL &x,LL &y) // ax+by=gcd(a,b)=d
{
	if(!b)
	{
		d=a; x=1; y=0;
	}
	else
	{
		exgcd(b,a%b,d,y,x);
		y-=a/b*x;
	}
}
LL inv(LL a,LL m)
{
    LL g,x,y;
    exgcd(a,m,g,x,y);
    if(g!=1) return -1;
    return (x%m+m)%m;
}


const int M=105;
LL ai[M],mi[M];
LL crt(LL ai[],LL mi[],int n)
{
	LL m=1,ans=0;
	for(int i=0;i<n;i++)
		m*=mi[i];
	for(int i=0;i<n;i++)
		ans=(ans+ai*inv(m/mi[i],mi[i])%m*(m/mi)%m)%m;
	return ans;
}