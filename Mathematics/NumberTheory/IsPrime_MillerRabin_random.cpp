#include <iostream>
#include <stdio.h>
#include <time.h>
#include <chrono>
#include <random>
using namespace std;

typedef long long LL;
mt19937 rn(chrono::system_clock::now().time_since_epoch().count());

const int MT=100;

LL rnd(LL n) // 0~n-1
{
	return (LL)rn()*rn()%n;
}

LL qm(LL a,LL b,LL m)
{
	LL ans=0;
	a%=m; b%=m;
	while(b)
	{
		if(b) ans=(ans+a)%m;
		a=(a+a)%m;
		b>>=1;
	}
	return ans;
}

LL qp(LL a,LL n,LL m)
{
	LL ans=1;
	a%=m;
	while(n)
	{
		if(n&1) ans=qm(ans,a,m);
		a=qm(a,a,m);
		n>>=1;
	}
	return ans;
}

bool witness(LL n,LL base)
{
	LL u=n-1;
	int j=0;
	while(u%2==0) u/=2,j++;
	LL x=qp(base,u,n);
	if(x==1||x==n-1) return true;
	while(j--)
	{
		x=x*x%n;
		if(x==n-1) return true;
	}
	return false;
}
// 4^(-MT) prob get wrong answer
// MT * log(n) (maybe another log (n) for qm)
bool ispMR(LL n) 
{
	if(n==2) return true;
	if(n<2||n%2==0) return false;
	for(int i=0;i<MT;i++)
	{
		LL base=rnd(n-1)+1;
		if(!witness(n,base)) return false;
	}
	return true;
}
