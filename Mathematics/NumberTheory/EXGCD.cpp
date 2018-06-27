typedef long long LL;

void exgcd(LL a,LL b,LL &d,LL &x,LL &y) // ax+by=gcd(a,b)=d
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

// ax+by=c 
// gcd(a,b)=g  ax'+by'=g
// => x'0 y'0
// n=a/g  m=b/g
// x'=x'0+km  y'=y'0-kn
// x=c/g *x'  y=c/g *y'



// ax=b(mod m) => ax+my=b