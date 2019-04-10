#include <iostream>

bool isprime(int n)
{
	if(n==1) return false;
	if(n==2) return true;
	for(int i=2;i<=n/i;i++)
		if(n%i==0) return false;
	return true;
}

bool inprime2(int n)
{
	if(n==1) return false;
	if(n==2||n==3) return true;
	if(n%6!=1&&n%6!=5) return false;
	for(int i=5;i<=n/i;i+=6)
		if(n%i==0||n%(i+2)==0) return false;
	return true;
}