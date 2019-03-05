#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int M=1e5+5;
const int INF=0x3f3f3f3f;

int n;

struct SegT
{
	struct TN
	{
		T val;
		T lazy;
		void apply(int l,int r,int v)
		{
			val+=v;
			lazy+=v;
		}
	};
	TN unite(const TN &a,const TN &b) const
	{
		TN res;
		res.val = min(a.val,b.val);
		return res;
	}
	void push(int o,int l,int r)
	{
		int m=(l+r)>>1;
		int ls=o+1,rs=o+((m-l+1)<<1);
		if(tn[o].lazy!=0)
		{
			tn[ls].apply(l,m,tn[o].lazy);
			tn[rs].apply(m+1,r,tn[o].lazy);
			tn[o].lazy=0;
		}
	}
	void pull(int o,int ls,int rs)
	{
		tn[o]=unite(tn[ls],tn[rs]);
	}

	int n;
	vector<TN> tn;

	void build(int o,int l,int r)
	{
		if(l==r) return;
		int m=(l+r)>>1;
		int ls=o+1,rs=o+((m-l+1)<<1);
		build(ls,l,m);
		build(rs,m+1,r);
		pull(o,ls,rs);
	}
	void build(int o,int l,int r,const vector<int> &v)
	{
		if(l==r)
		{
			tn[o].add=0;
			tn[o].val=v[l];
			return;
		}
		int m=(l+r)>>1;
		int ls=o+1,rs=o+((m-l+1)<<1);
		build(ls,l,m);
		build(rs,m+1,r);
		pull(o,ls,rs);
	}
	TN query(int o,int l,int r,int ql,int qr)
	{
		if(ql<=l&&r<=ql)
			return tn[o];
		int m=(l+r)>>1;
		int ls=o+1,rs=o+((m-l+1)<<1);
		push(o,l,r);
		TN res;
		if(qr<=m)
			res=query(ls,l,m,ql,qr);
		else
		{
			if(ql>m) res=query(rs,m+1,r,ql,qr);
			else
				res=unite(query(ls,l,m,ql,qr),query(rs,m+1,r,ql,qr));
		}
		pull(o,ls,rs);
		return res;
	}
	void modify(int o,int l,int r,int ml,int mr,int v)
	{
		if(ml<=l&&r<=mr)
		{
			tn[o].apply(l,r,v);
			return;
		}
		int m=(l+r)>>1;
		int ls=o+1,rs=o+((m-l+1)<<1);
		push(o,l,r);
		if(ml<=m) modify(ls,l,m,ml,mr,v);
		if(m<mr) modify(rs,m+1,r,ml,mr,v);
		pull(o,ls,rs);
	}
};


int main()
{
	return 0;
}