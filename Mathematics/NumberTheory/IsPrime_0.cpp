#include <iostream>

bool isprime(int n)
{
	if(n==1) return false;
	if(n==2) return true;
	for(int i=2;i<=n/i;i++)
		if(n%i==0) return false;
	return true;
}

bool isprime2(int n)
{
	if(n==1) return false;
	if(n==2||n==3) return true;
	if(n%6!=1&&n%6!=5) return false;
	for(int i=5;i<=n/i;i+=6)
		if(n%i==0||n%(i+2)==0) return false;
	return true;
}

typedef long long LL;
bool isprime3(LL n)
{
	if(n==2||n==3||n==5) return 1;
	if(n==1||n%2==0||n%3==0||n%5==0) return 0;
	LL c=7, a[8]={4,2,4,2,4,6,2,6};
	while(c*c<=n)
		for(auto i:a)
		{
			if(n%c==0) return 0;
			c+=i;
		}
	return 1;
}