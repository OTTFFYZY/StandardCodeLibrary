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
		for(int i=ln[c].d;i!=c;i=ln[i].d)
			linklr(tn[i].l,tn[i],r);
	}
	void resume(int c)
	{
		for(int i=ln[c].u;i!=c;i=ln[i].u)
		{
			linklr(ln[i].l,i);
			linklr(i,ln[i].r);
		}
	}
	int v[MR];
	int h() // A*
    {
        int ret=0;
        for(int c=tn[0].r;c!=0;c=tn[c].r)
            v[c]=1;
        for(int c=tn[0].r;c!=0;c=tn[c].r)
            if(v[c])
            {
                ret++;
                v[c]=0;
                for(int i=tn[c].d;i!=c;i=tn[i].d)
                    for(int j=tn[i].r;j!=i;j=tn[j].r)
                        v[tn[j].col]=0;
            }
        return ret;
    }
    int h2() // A* get max ansd
    {
        int ret=0;
        for(int c=tn[0].r;c!=0;c=tn[c].r)
            ret++;
        return ret;
    }
	void dance(int d)
	{
		if(d+h()>=ansd) return;
		if(ln[0].r==0) // all cols covered
		{
			ansd=d;
			return;
		}
		int c=ln[0].r;
		for(int i=ln[0].r;i!=0;i=ln[i].r)
			if(C[i]<C[c]) c=i; // minimum nodes
		for(int i=ln[c].d;i!=c;i=ln[i].d)
		{
			remove(i);
			ans[d]=ln[i].row;
			for(int j=ln[i].r;j!=i;j=ln[j].r)
				remove(j);
			dance(d+1);
			for(int j=ln[i].l;j!=i;j=ln[j].l)
				resume(j);
			resume(i);
		}
	}
};

int main()
{
	return 0;
}