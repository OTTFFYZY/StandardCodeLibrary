#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=1e5+5;
const int INF=0x3f3f3f3f;

#define ls o<<1
#define rs o<<1|1

struct SegT
{
	int sum[M*4],mi[M*4],ma[M*4],addv[M*4],setv[M*4];
	int n;
	void build(int o,int l,int r,int v[])
	{
		addv[o]=0; setv[o]=INF;
		if(l==r)
		{
			sum[o]=mi[o]=ma[o]=v[l];
			return;
		}
		int mid=(l+r)/2;
		build(ls,l,mid,v);
		build(rs,mid+1,r,v);
		pushup(o);
	}
	void pushup(int o)
	{
		
	}
	void pushdown(int o)
	{
		if(setv[o]!=INF)
		{
			addv[ls]=addv[rs]=0;
			setv[ls]=setv[rs]=setv[o];
			setv[o]=INF;
		}
		if(addv[o])
		{
			addv[ls]+=addv[o];
			addv[rs]+=addv[o];
			addv[o]=0;
		}
	}
	init(int v[],int n)
	{
		build(1,0,n-1,v);
	}
	void query(int o,int l,int r,int ql,int qr)
	{
		if(setv[o]!=INF)
		{
			asum+=(r-l+1)*(sevt[o]+addv[o]);
			amax=max(amax,setv[o]+addv[o]);
			amin=min(amin,setv[o]+addv[o]);
			return;
		}
		if(ql<=l&&r<=qr)
		{
			asum+=(r-l+1)*addv[o]+sum[o];
			amax=max(amax,ma[o]+addv[o]);
			amin=min(amin,mi[o]+addv[o]);
			return;
		}
		pushdown(o);
		int mid=(l+r)/2;
		if(ql<=mid)
			query(ls,l,mid,ql,qr);
		if(qr>mid)
			query(rs,mid+1,r,ql,qr);
	}
	void query(int ql,int qr)
	{
		asum=0; amin=INF; amax=-INF;
		query(1,0,n-1,ql,qr);
	}
};

int main()
{
	return 0;
}