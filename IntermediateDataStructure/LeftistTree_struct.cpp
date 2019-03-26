#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int M=1e5+5;

struct Leftist
{
	struct TN
	{
		int v,d;
		int l,r;
		bool operator<(const TN &B) const
		{
			return v<B.v; // big top
		}
	}tn[M];
	int nn;
	void init() // init liftist forest
	{
		nn=0;
	}
	void pull(int o)
	{
		int &ls=tn[o].l;
		int &rs=tn[o].r;
		if(tn[ls].d<tn[rs].d)
			swap(ls,rs);
		tn[o].d=tn[rs].d+1;
	}
	int merge(int x,int y) // merge tree x and tree y
	{
		if(!x||!y) return x+y;
		if(tn[x]<tn[y]) swap(x,y);
		tn[x].r=merge(tn[x].r,y);
		pull(x);
	}
	int newnode(int v)
	{
		tn[++nn].v=v;
		tn[nn].l=tn[nn].r=tn[nn].d=0;
		return nn;
	}
	int insert(int x,int v) // insert v in tree x
	{
		return merge(x,newnode(v));
	}
	int top(int x)  // return val of tree x
	{
		return tn[x].v;
	}
	int pop(int x)  // return new root
	{
		return merge(tn[x].l,tn[x].r);
	}
};

int main()
{
	return 0;
}