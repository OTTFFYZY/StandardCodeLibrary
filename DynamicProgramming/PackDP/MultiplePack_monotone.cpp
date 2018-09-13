#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

const int M=1e5+5;
int qu[M],ql,qr;
int w[M],v[M],n[M];
int V,N;
int dp[M];

int multipack(int w,int v,int n)
{
	if(v*n>V) n=V/v;
	for(int d=0;d<v;d++)
	{
		ql=qr=0;
		for(int i=d;i<=V;i+=v)
		{
			
		}
	}
		
}

int solve()
{
	memset(dp,0,sizeof(dp));
	for(int i=0;i<N;i++)
		multipack(w[i],v[i],n[i]);
	return dp[V];
}