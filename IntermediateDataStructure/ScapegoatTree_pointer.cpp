#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

const int M=1e5+5;
const double ALPHA=0.75; // rotation factor

struct ScapegoatTree
{
	struct TN
	{
		int v,si,nn; // value, size, number of nodes
		int ext;     // exist
		TN *ch[2];   // children
		void pull()
		{
			si=ch[0]->si+ch[1]->si+ext;
			nn=ch[0]->nn+ch[1]->nn+1;
		}
		bool isbad()
		{
			return ch[0]->nn > nn*ALPHA+5 || ch[1]->nn > nn*ALPHA+5;
		}
	};
	TN *root,*nil;
	struct MP
	{
		TN a[M];
		TN* d[M];
		TN *pa,**pd;
		void init()
		{
			pa=a;
			pd=d;
		}
		TN* get()
		{
			return pd!=d ? *(--pd) : pa++;
		}
		void rem(TN *u)
		{
			*(pd++)=u;
		}
	};
	MP pool;
	
	void init()
	{
		pool.init();
		nil=pool.get();
		root=nil;
		nil->si = nil->nn = nil->ext = 0;
		nil->ch[0] = nil->ch[1] = nil;
	}
	TN *newnode(int v)
	{
		TN *u=pool.get();
		u->v = v;
		u->si = u->nn = u->ext = 1;
		u->ch[0] = u->ch[1] = nil;
		return u;
	}
	TN **insert(TN *&u,int v)
	{
		if(u==nil)
		{
			u=newnode(v);
			return &nil;
		}
		u->si++; u->nn++;
		TN **res=insert(u->ch[v >= u->v],v);
		if(u->isbad()) res=&u;
		return res;
	}
	void erase(TN *&u,int k)
	{
		u->si--;
		int offset=u->ch[0]->si + u->ext;
		if(u->ext && k==offset)
		{
			u->ext=0;
			return;
		}
		if(k<=offset) erase(u->ch[0],k);
		else erase(u->ch[1],k-offset);
	}
	vector<TN*> vec;
	void travel(TN *u)
	{
		if(u==nil) return;
		travel(u->ch[0]);
		if(u->ext) vec.push_back(u);
		else pool.rem(u);
		travel(u->ch[1]);
	}
	TN* divide(int l,int r)
	{
		if(l>r) return nil;
		int mid=(l+r)>>1;
		TN *u=vec[mid];
		u->ch[0]=divide(l,mid-1);
		u->ch[1]=divide(mid+1,r);
		u->pull();
		return u;
	}
	void rebuild(TN *&u)
	{
		vec.clear();
		travel(u);
		u=divide(0,vec.size()-1);
	}

	void insert(int v)
	{
		TN **res=insert(root,v);
		if(*res!=nil) rebuild(*res);
	}
	int rank(int v)
	{
		TN *u=root;
		int ans=1;
		while(u!=nil)
		{
			if(u->v > v) u=u->ch[0];
			else
			{
				ans+=u->ch[0]->si + u->ext;
				u=u->ch[1];
			}
		}
		return ans;
	}
	int kth(int k)
	{
		TN *u=root;
		while(u!=nil)
		{
			int offset=u->ch[0]->si+u->ext;
			if(offset==k && u->ext) return u->v;
			else if(offset >= k) u=u->ch[0];
			else
			{
				k-=offset;
				u=u->ch[1];
			}
		}
		//return -1;
	}
	void erase_kth(int k)
	{
		erase(root,k);
		if(root->si < root->nn*ALPHA) rebuild(root);
	}
	void erase(int v)
	{
		erase(root,rank(v));
		if(root->si < root->nn*ALPHA) rebuild(root);
	}
};

int main()
{

	return 0;
}