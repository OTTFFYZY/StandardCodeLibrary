#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=1e6+5;
const int INF=1e9+7;

struct TN
{
	int sum,mi,ma; // sum min max
	int ad,se; // add set
	int l; // length
	TN(int sum=0,int mi=0,int ma=0,int ad=0,int se=0,int l=0)
		:sum(sum),mi(mi),ma(ma),ad(ad),se(se),l(0){}
	void s(int v)
	{
		mi=ma=se=v;
		ad=0;
		sum=l*v;
	}
	void a(int v)
	{
		mi+=v; ma+=v; ad+=v;
		sum+=v*l;
	}
};

struct SegT
{
	TN tn[M*2];
	int n;
	void build(int o,int l,int r)
	{	
		tn[o]=TN();
		tn[o].l=r-l+1;
		if(l==r) return;
		int m=(l+r)>>1;
		int ls=o+1,rs=o+((m-l+1)<<1);
		build(ls,l,m);
		build(rs,m+1,r);
	}
	void init(int _n)
	{
		n = _n;
		build(0,1,n); // 1-n segment tree
	}
	void push(int o,int ls,int rs)
	{
		if(tn[o].se>0)
		{
			tn[ls].s(tn[o].se);
			tn[rs].s(tn[o].se);
			tn[o].se=0;
		}
		if(tn[o].ad>0)
		{
			tn[ls].a(tn[o].ad);
			tn[rs].a(tn[o].ad);
			tn[o].ad=0;
		}
	}
	TN unite(const TN &a,const TN &b)
	{
		TN res;
		res.l=a.l+b.l;
		res.sum=a.sum+b.sum;
		res.ma=max(a.ma,b.ma);
		res.mi=min(a.mi,b.mi);
		return res;
	}
	void pull(int o,int ls,int rs)
	{
		tn[o]=unite(tn[ls],tn[rs]);
	}
	int L,R,V;
	void setv(int l,int r,int v)
	{
		L=l; R=r; V=v;
		_setv(0,1,n);
	}
	void _setv(int o,int l,int r)
	{
		if(L<=l&&r<=R)
		{
			tn[o].s(V);
			return;
		}
		int m=(l+r)>>1;
		int ls=o+1,rs=o+((m-l+1)<<1);
		push(o,ls,rs);
		if(L<=m) _setv(ls,l,m);
		if(m<R) _setv(rs,m+1,r);
		pull(o,ls,rs);
	}
	void addv(int l,int r,int v)
	{
		L=l; R=r; V=v;
		_addv(0,1,n);
	}
	void _addv(int o,int l,int r)
	{
		if(L<=l&&r<=R)
		{
			tn[o].a(V);
			return;
		}
		int m=(l+r)>>1;
		int ls=o+1,rs=o+((m-l+1)<<1);
		push(o,ls,rs);
		if(L<=m) _addv(ls,l,m);
		if(m<R) _addv(rs,m+1,r);
		pull(o,ls,rs);
	}
	TN query(int l,int r)
	{
		L=l; R=r;
		return _query(0,1,n);
	}
	TN _query(int o,int l,int r)
	{
		if(L<=l&&r<=R) return tn[o];
		int m=(l+r)>>1;
		int ls=o+1,rs=o+((m-l+1)<<1);
		push(o,ls,rs);
		TN res;
		if(R<=m) res=_query(ls,l,m);
		else if(L>m) res=_query(rs,m+1,r);
		else res=unite(_query(ls,l,m),_query(rs,m+1,r));
		pull(o,ls,rs);
		return res;
	}
}segt;

int main()
{
	return 0;
}