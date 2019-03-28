#include <iostream>
#include <stdio.h>
#include <random>
#include <chrono>
#include <algorithm>
using namespace std;

const int M=1e5+5;
int w[M],sum[M],n;
mt19937 rn(chrono::system_clock::now().time_since_epoch().count());

void init()
{
	for(int i=0;i<n;i++)
		sum[i+1]=sum[i]+w[i];
}

int rnd()
{
	return upper_bound(sum,sum+n+1,rn()%sum[n])-sum-1;
}

int main()
{
	w[0]=1; w[1]=20; w[2]=100; n=3;
	init();
	for(int i=0;i<100;i++)
		cout<<rnd()<<" ";
	cout<<endl;
	return 0;
}