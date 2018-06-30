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

// ax+by=c 
// gcd(a,b)=g  ax'+by'=g
// => x'0 y'0
// n=a/g  m=b/g
// x'=x'0+km  y'=y'0-kn
// x=c/g *x'  y=c/g *y'
bool solve(LL a,LL b,LL c,LL &x,LL &y)
{
    LL g;
    exgcd(a,b,g,x,y);
    if(c%g) return 0;
    x*=c/g;
    y*=c/g;
    return 1;
}

// ax=b(mod m) => ax+my=b