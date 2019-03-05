#include <iostream>
#include <algorithm>
using namespace std;

const int M=1e5+5;
const int INF=0x3f3f3f3f;

struct SegT
{
	int tn[M*2];
	void pull(int o,int ls,int rs)
	{
		tn[o]=max(tn[ls],tn[rs]);
	}
	void init(int v[],int n)
	{
		build(0,0,n-1,v);
	}
	void build(int o,int l,int r,int v[])
	{
		if(l==r)
		{
			tn[o]=v[l];
			return;
		}
		int mid=(l+r)>>1;
		int ls=o+1,rs=o+((mid-l+1)<<1);
		build(ls,l,mid,v);
		build(rs,mid+1,r,v);
		pull(o,ls,rs);
	}
	int L,R,V;
	void add(int o,int l,int r)
	{
		if(l==r)
		{
			tn[o]=V;
			return;
		}
		int mid=(l+r)>>1;
		int ls=o+1,rs=o+((mid-l+1)<<1);
		if(L<=mid) add(ls,l,mid);
		else add(rs,mid+1,r);
		pull(o,ls,rs);
	}
	int query(int o,int l,int r)
	{
		if(L<=l&&r<=R)
			return tn[o];
		int mid=(l+r)>>1;
		int ls=o+1,rs=o+((mid-l+1)<<1);
		int res=-INF;
		if(L<=mid) res=max(res,query(ls,l,mid));
		if(mid<R) res=max(res,query(rs,mid+1,r));
		return res;
	}
};


int main()
{
	return 0;
}