#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

const int M=1e5+5;
int qu[M],qub[M],ql,qr;
int w[M],v[M],n[M];
int V,N;
int dp[M];

void showq(int q[])
{
	for(int i=ql;i<qr;i++)
		cout<<q[i]<<" ";
	cout<<endl;
}

void multipack(int w,int v,int n)
{
	for(int d=0;d<v;d++)
	{
		ql=qr=0;
		int k=(V-d)/v;
		for(int i=0;i<=k;i++)
		{
			int nv=dp[i*v+d]-w*i;
			while(ql<qr&&qu[qr-1]<=nv) qr--;
			qub[qr]=i; qu[qr++]=nv;
			if(ql<qr&&i-qub[ql]>n) ql++;
			dp[i*v+d]=qu[ql]+w*i;
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

int main()
{
	V=10;
	N=3;
	w[0]=3; v[0]=2; n[0]=3;
	w[1]=2; v[1]=3; n[1]=2;
	w[2]=5; v[2]=3; n[2]=2;
	cout<<solve()<<endl;
	return 0;
}