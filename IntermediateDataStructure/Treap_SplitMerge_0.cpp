#include <iostream>
#include <stdio.h>
#include <string.h>
#include <chrono>
#include <random>
#include <algorithm>
using namespace std;

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());

const int M=1e5+5;
const int INF=0x3f3f3f3f;

struct Treap
{
	struct TN
	{
		int v,rn;
		int l,r;
		int sz;
	}tn[M];
	int nn;
	int root;
	void init()
	{
		nn=root=0;
		tn[0].v=tn[0].l=tn[0].r=tn[0].sz=0;
	}
	void pull(int o)
	{
		tn[o].sz=tn[tn[o].l].sz+tn[tn[o].r].sz+1;
	}
	void merge(int &o,int x,int y)
	{
		if(!x||!y)
		{
			o=x+y;
			return;
		}
		if(tn[x].rn<tn[y].rn)
			o=x, merge(tn[o].r,tn[x].r,y);
		else
			o=y, merge(tn[o].l,x,tn[y].l);
		pull(o);
	}

	// tn[x] <= v, tn[y] > v
	void split(int o,int v,int &x,int &y) 
	{
		if(!o)
		{
			x=y=0;
			return;
		}
		if(tn[o].v<=v)
			x=o, split(tn[o].r,v,tn[x].r,y);
		else
			y=o, split(tn[o].l,v,x,tn[y].l);
		pull(o);
	}

	// tn[x].sz == k
	void split_kth(int o,int k,int &x,int &y)
	{
		if(!o)
		{
			x=y=0;
			return;
		}
		int lsz=tn[tn[o].l].sz+1;
		if(lsz<=k)
			x=o, split_kth(tn[o].r,k-lsz,tn[x].r,y);
		else
			y=o, split_kth(tn[o].l,k,x,tn[y].l);

		pull(o);
	}
	int newnode(int v)
	{
		int o=++nn;
		tn[o].v=v; tn[o].rn=rnd(); 
		tn[o].l=tn[o].r=0;
		tn[o].sz=1;
		return o;
	}
	void insert(int &o,int v)
	{
		int x,y,z=newnode(v);
		split(o,v,x,y);
		merge(x,x,z);
		merge(o,x,y);
	}
	void remove(int &o,int v)
	{
		int x,y,z;
		split(o,v,x,y);
		split(x,v-1,x,z);
		merge(z,tn[z].l,tn[z].r);
		merge(x,x,z);
		merge(o,x,y);
	}
	int rank(int &o,int v)
	{
		int x,y; split(o,v-1,x,y);
		int res=tn[x].sz+1;
		merge(o,x,y);
		return res;
	}
	int kth(int o,int k)
	{
		while(o)
		{
			int lsz=tn[tn[o].l].sz+1;
			if(k==lsz) return tn[o].v;
			if(k<lsz) o=tn[o].l;
			else o=tn[o].r, k-=lsz;
		}
		return -INF; // not find
	}
	int pre(int &o,int v)
	{
		int x,y;
		split(o,v-1,x,y);
		int res=kth(x,tn[x].sz);
		merge(o,x,y);
		return res;
	}
	int suc(int &o,int v)
	{
		int x,y;
		split(o,v,x,y);
		int res=kth(y,1);
		merge(o,x,y);
		return res;
	}
	void show(int o)
	{
		if(!o) return;
		cout<<o<<" "
			<<tn[o].v<<" "<<tn[o].rn<<" "
			<<tn[o].sz<<" "
			<<tn[o].l<<" "<<tn[o].r<<endl;
		show(tn[o].l);
		show(tn[o].r);
	}
}treap;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,op,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&op,&x);
		switch(op)
		{
			case 1:
				treap.insert(treap.root,x);
				break;
			case 2:
				treap.remove(treap.root,x);
				break;
			case 3:
				printf("%d\n",treap.rank(treap.root,x));
				break;
			case 4:
				printf("%d\n",treap.kth(treap.root,x));
				break;
			case 5:
				printf("%d\n",treap.pre(treap.root,x));
				break;
			case 6:
				printf("%d\n",treap.suc(treap.root,x));
		}
		/*
		cout<<"!! "<<endl;
		treap.show(treap.root);
		cout<<"&& "<<endl;
		*/
	}
	return 0;
}