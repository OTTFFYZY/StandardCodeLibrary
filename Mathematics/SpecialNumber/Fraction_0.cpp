#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

const int M=1e4+5;

struct Frac
{
	int a,b; // a/b
	int gcd(int x,int y)
	{
		return !y?x:gcd(y,x%y);
	}
	void trim()
	{
		int g=gcd(a,b);
		a/=g; b/=g;
	}
};

int main()
{
	return 0;
}