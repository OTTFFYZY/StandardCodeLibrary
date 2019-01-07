#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

const int M=1e4+5;
typedef long long LL;

struct Frac
{
	LL a,b; // a/b
	Frac(LL a=0,LL b=1):a(a),b(b)
	{
		trim();
	}
	int gcd(LL x,LL y)
	{
		return !y?x:gcd(y,x%y);
	}
	void trim()
	{
		int g=gcd(abs(a),abs(b));
		a/=g; b/=g;
		if(b<0)
		{
			a=-a; b=-b;
		}
	}
	bool operator==(const Frac &B) const
	{
		return a==B.a && b==B.b;
	}
	bool operator<(const Frac &B) const
	{
		return a*B.b < B.a*b;
	}
	Frac operator*(const Frac &B) const
	{
		return Frac(a*B.a, b*B.b);
	}
	Frac operator+(const Frac &B) const
	{
		return Frac(a*B.b+B.a*b, b*B.b);
	}
	Frac operator-(const Frac &B) const
	{
		return Frac(a*B.b-B.a*b, b*B.b);
	}
	Frac operator/(const Frac &B) const
	{
		return Frac(a*B.b, b*B.a);
	}
	void print()
	{
		printf("%d/%d\n",a,b);
	}
};

int main()
{
	return 0;
}