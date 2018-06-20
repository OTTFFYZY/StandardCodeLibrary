typedef long long LL;

void exgcd(LL a,LL b,LL &d,LL &x,LL &y)
{
	if(!b)
	{
		d=a;
		x=1; y=0;
	}
	else
	{
		exgcd(b,a%b,d,y,x);
		y-=a/b*x;
	}
}