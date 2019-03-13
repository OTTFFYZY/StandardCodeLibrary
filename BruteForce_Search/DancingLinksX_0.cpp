#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct DancingLinksX
{
	static const int MR=100;
	static const int MC=100;
	static const int MN=1005;
	struct LN
	{
		int l,r,u,d;
		int row,col;
		void init(int r,int c)
		{
			row=r; col=c;
		}
	};
	LN ln[MN]; int nn;
	int H[MR];  // rightest node of rows
	int C[MC];	// Number of Nodes in Column
	int ans[MC],nans; // nans rows selected
	int n,m;    // rows cols [1,n] [1,m]
	void linklr(int a,int b)
	{
		ln[a].r=b; ln[b].l=a;
	}
	void linkud(int a,int b)
	{
		ln[a].d=b;
		ln[b].u=a;
	}
	void init(int _n,int _m)
	{
		n=_n; m=_m;
		for(int i=0;i<=m;i++)
		{
			ln[i].init(0,i);
			linkud(i,i);
		}
		for(int i=1;i<=m;i++)
			linklr(i-1,i);
		linklr(m,0);
		nn=m;
		
		memset(C,0,sizeof(C));
		memset(H,-1,sizeof(H));
		nans=0;
	}

	void link(int r,int c)
	{
		++nn;
		C[c]++;
		ln[nn].init(r,c);
		int last=ln[0].u;
		linkud(ln[c].u,nn);
		linkud(nn,c);
		if(H[r]==-1)
			linklr(nn,nn);
		else
		{
			linklr(nn,ln[H[r]].r);
			linklr(H[r],nn);
		}
		H[r]=nn;
	}

	void remove(int c)
	{
		linklr(ln[c].l,ln[c].r);
		for(int i=ln[c].d;i!=c;i=ln[i].d)
			for(int j=ln[i].r;j!=i;j=ln[j].r)
			{
				linkud(ln[j].u,ln[j].d);
				C[ln[j].col]--;
			}
	}
	void resume(int c)
	{
		for(int i=ln[c].u;i!=c;i=ln[i].u)
			for(int j=ln[i].l;j!=i;j=ln[j].l)
			{
				C[ln[j].col]++;
				linkud(ln[j].u,j);
				linkud(j,ln[j].d);
			}
		linklr(ln[c].l,c);
		linklr(c,ln[c].r);
	}
	bool dance(int d)
	{
		if(ln[0].r==0) // all cols covered
		{
			ansd=d;
			return 1;
		}
		int c=ln[0].r;
		for(int i=ln[0].r;i!=0;i=ln[i].r)
			if(C[i]<C[c]) c=i; // minimum nodes
		remove(c);
		for(int i=ln[c].d;i!=c;i=ln[i].d)
		{
			ans[d]=ln[i].row;
			for(int j=ln[i].r;j!=i;j=ln[j].r)
				remove(ln[j].col);
			if(dance(d+1)) return 1;
			for(int j=ln[i].l;j!=i;j=ln[j].l)
				resume(ln[j].col);
		}
		resume(c);
		return 0;
	}
};

int main()
{
	return 0;
}