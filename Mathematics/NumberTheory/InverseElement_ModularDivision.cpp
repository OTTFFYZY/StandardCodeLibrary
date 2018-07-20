typedef long long LL;

// approach 1: gcd(a,m)==1 else return -1
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
// ax=1(mod m)
// => ax+my=1
LL inv1(LL a,LL m)
{
    LL g,x,y;
    exgcd(a,m,g,x,y);
    if(g!=1) return -1;
    return (x%m+m)%m;
}

// approach 2: gcd(a,m)==1 a<m
LL inv2(LL a,LL m)
{
	return a==0?1:inv(m%a,m)*(m-m/a)%m;
}
const int M=999983; // a prime
LL inv[M];
LL inv_table(int m) //O(m) m is a prime
{
	inv[1]=1;
    for(int i=2;i<m;i++)
        inv[i]=(m-m/i)*inv[m%i]%m;
}

// approach 3: m is prime, gcd(a,m)==1
// Fermat's little theorem
LL qp(LL a,LL n,LL m)
{
	LL ans=1;
	while(n)
	{
		if(n&1) ans=ans*a%m;
		a=a*a%m;
		n>>=1;
	}
	return ans;
}
LL inv3(LL a,LL m)
{
	a%=m;
	return qp(a,m-2,m);
}

// a/b mod m => (a mod bm)/b