#include <iostream>
#include <stdio.h>
#include <functional>
#include <algorithm>
using namespace std;

const int M=1e5+5;
int a[M]; 
int n;
int b[M];

// each part i a[i_0]<a[i_1]<a[i_2]...
int partition()
{
	int m=0;
	for(int i=0;i<n;i++)
	{
		int p=upper_bound(b,b+m,a[i],greater<int>())-b;
		b[p]=m;
		m=max(m,p+1);
	}
	return m;
}

int main()
{
	return 0;
}