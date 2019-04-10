#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

const int MB=3;
const LL BASE[]={2,7,61}; // 3 for [1-4 759 123 141]
//const LL base[]={2,3,5,7,11,13,17}; // 7 for [1 - 341 550 071 728 320] 
//const LL base[]={2,3,7,61,24251}; // 10^16 except 46 856 248 255 981

LL qp(LL a,LL n,LL m)
{
	LL ans=1;
	a%=m;
	while(n)
	{
		if(n&1) ans=ans*a%m;
		a=a*a%m;
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

bool ispMR(LL n)
{
	if(n<2) return false;
	for(int i=0;i<MB;i++)
		if(n==BASE[i]) return true;
	for(int i=0;i<MB;i++)
		if(n%BASE[i]==0) return false;
	for(int i=0;i<3;i++)
		if(!witness(n,BASE[i])) return false;
	return true;
}
