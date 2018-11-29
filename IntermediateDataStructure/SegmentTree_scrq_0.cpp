#include <iostream>
#include <algorithm>
using namespace std;

const int M=1e5+5;
const int INF=0x3f3f3f3f;

int n;
int ML,MR;
struct SegT
{
	int tn[M*4];
	void init(int v[],int n)
	{
		ML=0; MR=n-1;
		build(v,1,ML,MR);
	}
	void build(int v[],int o,int l,int r)
	{
		if(l==r)
		{
			tn[o]=v[l];
			return;
		}
		int mid=(l+r)>>1;
		build(v,o<<1,l,mid);
		build(v,o<<1|1,mid+1,r);
		pushup(o);
	}
	int pushup(int o)
	{
		tn[o]=max(tn[o<<1],tn[o<<1|1]);
	}
	int ans;
	int ql,qr;
	int query(int ql,int qr)
	{
		ans=-INF;
		this->ql=ql; this->qr=qr;
		query();
		return ans;
	}
	void query(int o=1,int l=ML,int r=MR)
	{
		if(ql<=l&&r<=qr)
		{
			ans=max(ans,tn[o]);
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid)
			query(o<<1,l,mid);
		if(qr>mid)
			query(o<<1|1,mid+1,r);
	}
	void add(int x,int p,int o=1,int l=ML,int r=MR)
	{
		if(l==r)
		{
			tn[o]+=x;
			return;
		}
		int mid=(l+r)>>1;
		if(p<mid)
			add(x,p,o<<1,l,mid);
		else
			add(x,p,o<<1|1,mid+1,r);
		pushup(o);
	}
};


int main()
{
	return 0;
}