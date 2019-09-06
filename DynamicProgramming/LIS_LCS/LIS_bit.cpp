#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;
const int M=1e5+5;
const int INF=0x3f3f3f3f;

struct LIS_BIT
{
	int t[M],a[M],p[M];
	void init()
	{
		memset(t,0,sizeof(t));
		memset(p,-1,sizeof(p));
	}
	int lowbit(int x)
	{
		return x&(-x);
	}
	PII getmax(int id)
	{
		int ans=0,mp=0;
		for(int i=id;i;i-=lowbit(i))
		{
			if(ans<i)
			{
				ans=t[i];
				mp=p[i];
			}
		}
		return make_pair(ans,mp);
	}
	void set(int id,int v,int np)
	{
		if(v<=a[id]) return;
		a[id]=v;
		for(int i=id;i<M;i+=lowbit(i))
		{
			if(v>t[i])
			{
				t[i]=v;
				p[i]=np;
			}
		}
	}
}bit;

int a[M]={9,6,1,3,4,5,6,5,6};
int dp[M];
int pre[M];
int lis(int n)
{
	bit.init();
	for(int i=0;i<n;i++)
	{
		PII p=bit.getmax(a[i]);
		dp[i]=p.first+1;
		pre[i]=p.second;
		bit.set(a[i],dp[i],i);
	}
	return dp[n-1];
}

int main()
{
	int n=9;
	cout<<lis(n)<<endl;
	for(int i=0;i<n;i++)
		cout<<i<<"\t";
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<dp[i]<<"\t";
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<pre[i]<<"\t";
	cout<<endl;
	return 0;
}