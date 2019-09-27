#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int M=1e5+5;
const double ALPHA=0.75;
const double BETA=0.30;

struct ScapegoatTree
{
	struct TN
	{
		int val;
		int sz,fac;
		int exist;
		int l,r;
		TN(int val=0,int sz=1,int fac=1,int exist=1,int l=0,int r=0)
			:val(val),sz(sz),fac(fac),exist(exist),l(l),r(r){}
	}tn[M];
	int nn=0;
	int root;
	void newnode(int &u,int val)
	{
		u=++nn;
		tn[u]=TN(val);
	}
	vector<int> tmp;
	void inorder(int u)
	{ 
		if(!u) return;
		inorder(tn[u].l);
		if(tn[u].exist) 
			tmp.push_back(u);
		inorder(tn[u].r);
	}
	void rebuild(int &u,int l,int r)
	{
		if(l==r)
		{
			u=tmp[l];
			tn[u].l=tn[u].r=0;
			tn[u].sz=tn[u].fac=1;
			//tn[u].exist=1;
			return;
		}
		int m=(l+r)>>1;
		while(m>l&&tn[tmp[m]].val==tn[tmp[m-1]].val)
			m--;
		u=tmp[m];
		if(m>l)
			rebuild(tn[u].l,l,m-1);
		else
			tn[u].l=0;
		rebuild(tn[u].r,m+1,r);
		tn[u].sz=r-l+1;
		tn[u].fac=r-l+1;
	}
	void check(int &u,int val,int end)
	{
		if(u==end) return;
		if(tn[u].sz*ALPHA<tn[tn[u].l].sz 
			|| tn[u].sz*ALPHA<tn[tn[u].r].sz
			|| tn[u].sz*BETA<tn[u].fac)
		{
			tmp.clear();
			inorder(u);
			rebuild(u,0,tmp.size()-1);
			return;
		}
		if(val<tn[u].val)
			check(tn[u].l,val,end);
		else
			check(tn[u].r,val,end);
	}
	void insert(int &u,int val)
	{
		if(!u)
		{
			newnode(u,val);
			check(root,u,val);
			return;
		}
		tn[u].sz++; tn[u].fac++;
		if(val<tn[u].val)
			insert(tn[u].l,val);
		else
			insert(tn[u].r,val);
	}
	void remove(int &u,int val)
	{
		if(tn[u].exist&&tn[u].val==val)
		{
			tn[u].fac--;
			tn[u].exist=0;
			check(root,u,val);
			return;
		}
		tn[u].fac--;
		if(val<tn[u].val)
			remove(tn[u].l,val);
		else
			remove(tn[u].r,val);
	}
};

int main()
{
	return 0;
}