#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int M=1e5+5;
int a[M],n;  //origin
int d[M],dn; //array after discretization
int get_id(int v)
{
	return lower_bound(d,d+dn,v)-d;
}

vector<int> a2;
vector<int> d2;
int get_id2(int v)
{
	return lower_bound(d2.begin(),d2.end(),v)-d2.begin();
}

int main()
{
	memcpy(d,a,sizeof(int)*n); dn=n;
	sort(d,d+dn);
	dn=unique(d,d+dn)-d;

	d2=a2;
	sort(d2.begin(),d2.end());
	d2.erase(unique(d2.begin(),d2.end()),d2.end());

	return 0;
}