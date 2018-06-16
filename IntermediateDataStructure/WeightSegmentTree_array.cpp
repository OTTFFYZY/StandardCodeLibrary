#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

const int M=4e5+5;

struct TN
{
	//int l,r;
	int size;
};

struct SegT
{
	TN tn[M*4];
	const static int WMIN=1;
	const static int WMAX=M;
	void init()
	{
		memset(tn,0,sizeof(tn));
	}
	void pushup(int o)
	{
		tn[o].size=tn[o<<1].size+tn[o<<1|1].size;
	}
	void ins(int x,int k,int o=1,int l=WMIN,int r=WMAX) // insert k x
	{
		if(l==r)
		{
			tn[o].size+=k;
			return;
		}
		int m=(l+r)/2;
		if(x<=m) ins(x,k,o<<1,l,m);
		else ins(x,k,o<<1|1,m+1,r);
		pushup(o);
	}
	int kth(int k,int o=1,int l=WMIN,int r=WMAX) // find K-th number
	{
		if(l==r) return l;
		int m=(l+r)/2;
		if(tn[o<<1].size>=k) 
			return kth(k,o<<1,l,m);
		else 
			return kth(k-tn[o<<1].size,o<<1|1,m+1,r);
	}
	int rank(int x,int o=1,int l=WMIN,int r=WMAX) // get the rank of x
	{
		if(l==r) return 1;
		int m=(l+r)/2;
		if(x<=m) 
			return rank(x,o<<1,l,m);
		else 
			return tn[o<<1].size+rank(x,o<<1|1,m+1,r);
	}
	int count(int x,int o=1,int l=WMIN,int r=WMAX) // get the number of x
	{
		if(l==r) return tn[o].size;
		int m=(l+r)/2;
		if(x<=m)
			return count(x,o<<1,l,m);
		else 
			return count(x,o<<1|1,m+1,r);
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