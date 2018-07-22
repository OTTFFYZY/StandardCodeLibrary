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

// approach 4: gcd(a,m)==1
// Euler theorem
LL phi(LL n)
{
	LL ans=n;
	for(LL i=2;i*i<=n;i++)
		if(n%i==0)
		{
			ans=ans/i*(i-1);
			while(n%i==0) n/=i;
		}
	if(n!=1) ans=ans/n*(n-1);
	return ans;
}
LL inv4(LL a,LL m)
{
	return qp(a,phi(m-1),m);
}

// approach 5:
// modular division, not inverse element
// a/b mod m => (a mod bm)/b