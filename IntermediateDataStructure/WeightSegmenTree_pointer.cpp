#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

const int M=1e5+5;
struct TN
{	
	TN *ls,*rs;
	int l,r,si;
};
namespace MP
{	
	TN a[M],*b[M];
	int pa,pb;
	void clear()
	{
		pa=pb=0;
	}
	TN* add(int l,int r)
	{
		TN *o=pb?b[--pb]:&a[pa];
		o->l=l; o->r=r;
		o->ls=o->rs=NULL;
		o->si=0;
		return o;
	}
	void del(T *x)
	{
		b[pb++]=x;
	}
}

struct SegT
{
	TN *root;
	const static int WMIN=1;
	const static int WMAX=M;
	void init()
	{
		MP::clear();
		root=MP::add(WMIN,WMAX);
	}
	void pushup(TN *o)
	{
		o->si=0;
		if(o->ls) o->si+=o->ls->si;
		if(o->rs) o->si+=o->rs->si;
	}
	void ins(int x,int k,TN *o=root,int l=WMIN,int r=WMAX) // insert k x
	{
		if(l==r)
		{
			o->si+=k;
			return;
		}
		int m=(l+r)/2;
		if(x<=m)
		{
			if(!o->ls) o->ls=MP::add(l,m);
			ins(x,k,o->ls,l,m);
		}
		else
		{   
			if(!o->rs) o->rs=MP::add(m+1,r);
			ins(x,k,o->rs,m+1,r);
		}
		pushup(o);
	}
	int kth(int k,TN *o=root,int l=WMIN,int r=WMAX) // find K-th number
	{
		if(l==r) return l;
		int m=(l+r)/2;
		if(o->si>=k) 
			return kth(k,o->ls,l,m);
		else 
			return kth(k-o->ls->si,o->rs,m+1,r);
	}
	int rank(int x,TN *o=root,int l=WMIN,int r=WMAX) // get the rank of x
	{
		if(l==r) return 1;
		int m=(l+r)/2;
		if(x<=m) 
			return rank(x,o->ls,l,m);
		else 
			return o->ls.si+rank(x,o->rs,m+1,r);
	}
	int count(int x,TN *o=root,int l=WMIN,int r=WMAX) // get the number of x
	{
		if(l==r) return o->si;
		int m=(l+r)/2;
		if(x<=m)
			return count(x,o->ls,l,m);
		else 
			return count(x,o->rs,m+1,r);
	}
	int pre(int x)
	{
		return kth(rank(x)-1);
	}
	int post(int x)
	{
		return kth(rank(x)+1);
	}
}segt;

int main()
{
	segt.init();
	cout<<"init ok!"<<endl<<endl;
	segt.ins(1,10);
	segt.ins(1,10);
	segt.ins(5,3);
	segt.ins(15,1);
	segt.ins(12,1);
	cout<<"kth(20) "<<segt.kth(20)<<" kth(21) "<<segt.kth(21)<<endl;
	cout<<"kth(0) "<<segt.kth(0)<<" kth(25) "<<segt.kth(25)<<" kth(26) "<<segt.kth(26)<<endl;
	cout<<"rank(1) "<<segt.rank(1)<<" rank(2) "<<segt.rank(2)<<endl;
	cout<<"rank(0) "<<segt.rank(0)<<" rank(5) "<<segt.rank(5)<<" rank(15) "<<segt.rank(15)<<endl;
	return 0;
}
