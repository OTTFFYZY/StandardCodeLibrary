typedef long long LL;


LL qm(LL a,LL n,LL m)
{
	LL ans=0;
	while(n)
	{
		if(n&1) ans=(ans+a)%m;
		a=(a+a)%m;
		n>>=1;
	}
	return ans;
}
LL qp(LL a,LL n,LL m)
{
	LL ans=1;
	while(n)
	{
		if(n&1) ans=qm(ans,a,m);
		a=qm(a,a,m);
		n>>=1;
	}
	return ans;
}

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

LL bp(LL a,LL n,LL m) //a^n%m  big n
{
	LL p=phi(m);
	return n>=p?qp(a,n%p+p,m):qp(a,n,m);
}

LL bp2(LL a,str *s,LL m) //a^s%m  big n
{
	LL p=phi(m),n=0;
	int f=0;
	for(;*s;s++)
	{
		n=n*10+(*s)-'0';
		if(n>=p) f=1;
		n%=p;
	}
	return f?qp(a,n+p,m):qp(a,n,m);
}