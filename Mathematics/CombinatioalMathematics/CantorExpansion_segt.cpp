#include <iostream>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
using namespace std;

const int M=50005;
int ss[M];
typedef long long LL;

struct SegT
{
	int si[M*2];
	void build(int o,int l,int r)
	{
		si[o]=r-l+1;
		if(l==r) return;
		int m=(l+r)>>1;
		int ls=o+1,rs=o+((m-l+1)<<1);
		build(ls,l,m);
		build(rs,m+1,r);
	}
	int kth(int o,int l,int r,int k)
	{
		//cout<<"   "<<l<<" "<<r<<" "<<si[o]<<endl;
		si[o]--;
		if(l==r)
			return l;
		int m=(l+r)>>1;
		int ls=o+1,rs=o+((m-l+1)<<1);
		if(k<=si[ls]) return kth(ls,l,m,k);
		else return kth(rs,m+1,r,k-si[ls]);
	}
	int rank(int o,int l,int r,int v)
	{
		si[o]--;
		if(l==r) return 0; // special from 0
		int m=(l+r)>>1;
		int ls=o+1,rs=o+((m-l+1)<<1);
		if(v<=m) return rank(ls,l,m,v);
		else return rank(rs,m+1,r,v)+si[ls];
	}
};
struct Cantor
{
	SegT segt;
	int k;
	int p[M],s[M];
	LL n; // k < 21
	// p[0~k-1] -> permutation of 1~k
	// s[0~k-1] -> n = s[0]*(k-1)!+s[1]*(k-2)!+...+S[k-2]*1!+S[k-1]*0!
	// n -> 0 ~ k!-1
	void p2s()
	{
		segt.build(0,1,k);
		for(int i=0;i<k;i++)
			s[i]=segt.rank(0,1,k,p[i]);
	}
	void s2p()
	{
		segt.build(0,1,k);
		for(int i=0;i<k;i++)
			p[i]=segt.kth(0,1,k,s[i]+1);
	}
	LL s2n()
	{
		n=0;
		LL f=1;
		for(LL i=k-1,j=1;i>=0;i--,j++)
		{
			n+=s[i]*f;
			f*=j;
		}
		return n;
	}
	void n2s(LL _n)
	{
		n=_n;
		s[k-1]=0;
		for(LL i=k-2,j=2;i>=0;i--,j++)
		{
			s[i]=_n%j;
			_n/=j;
		}
	}
	void n2p(LL _n)
	{
		n2s(_n);
		s2p();
	}
	LL p2n()
	{
		p2s();
		return s2n();
	}
	void showp()
	{
		for(int i=0;i<k;i++)
			printf("%d%c",p[i],i==k-1?'\n':' ');	
	}
	void shows()
	{
		for(int i=0;i<k;i++)
			printf("%d%c",s[i],i==k-1?'\n':' ');
	}
}cantor;

int main()
{
	/*
	LL i,ans=1;
	for(i=1;i<=LLONG_MAX/ans;i++)
		ans*=i;
	cout<<i<<endl;
	*/
	cantor.k=4; // 5*4*3*2*1=24
	for(int i=0;i<24;i++)
	{
		printf("%d:\n",i);
		cantor.n2p(i);
		cantor.shows();
		cantor.showp();
		cantor.p2s();
		cantor.shows();
		printf("%I64d\n\n",cantor.s2n());
	}
	return 0;
}