#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

bool wythoff(int n,int m)
{
	if(n<m) swap(n,m);
	double gold=(sqrt(5.0)+1.0)/2.0;
	return (int)(gold*(n-m))!=m;
}

int main()
{
	cout<<wythoff(3,5)<<endl;
	cout<<wythoff(1,2)<<endl;
	cout<<wythoff(1,3)<<endl;
	return 0;
}