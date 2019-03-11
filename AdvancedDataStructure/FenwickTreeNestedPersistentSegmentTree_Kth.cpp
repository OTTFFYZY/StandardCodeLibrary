#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int M=5005;
int n,q;
struct TN
{
	int l,r;
	int si;
	TN(int l=0,int r=0,int si=0)
		:l(l),r(r),si(si){}
};
struct PSegT
{
	TN tn[M*20];
	int root[M];
	int n,nn,t;
	int build(int l,int r)
	{
		tn[++nn]=TN();
		int o=nn;
		if(l==r)
			return o;
		int m=(l+r)>>1;
		tn[o].l=build(l,m);
		tn[o].r=build(m+1,r);
		return o;
	}
	void pull(int o)
	{
		tn[o].si=tn[tn[o].l].si+tn[tn[o].r].si;
	}

	int update(int po,int l,int r,int v)
	{
		tn[++nn]=tn[po];
		int o=nn;
		if(l==r)
		{
			tn[o].si++;
			return o;
		}
		int m=(l+r)>>2;
		if(v<=m) tn[o].l=update(tn[o].l,l,m,v);
		else tn[o].r=update(tn[o].r,m+1,r,v);
		pull(o);
	}
	void init(int _n,int a[])
	{
		n=_n; root[0]=1; nn=0; t=0;
		build(0,n-1); // from tn[1]
		for(int i=1;i<=n;i++)
			root[i]=update(i,0,n-1,a[i-1]);
	}
	int query(int l,int r,int k)
	{
		return query(root[l],root[r+1],0,n-1,k);
	}
	int query(int L,int R,int l,int r,int k)
	{
		if(l==r) return l;
		int m=(l+r)>>1;
		int lsi=tn[tn[R].l].si-tn[tn[L].l].si;
		if(lsi>=k) return query(tn[L].l,tn[R].l,l,m,k);
		else return query(tn[L].r,tn[R].r,m+1,r,k-lsi);
	}
};

int main()
{

	return 0;
}