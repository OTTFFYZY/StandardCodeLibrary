#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int MR=; // number of row
const int MC=; // number of column
const int MN=; // number of node
struct CLLNode // Crossing Linked List Node
{
	int u,d,l,r,col,row;
	void CLLNode(int u=0,int d=0,int l=0,int r=0,int row=0,int col=0)
		:u(u),d(d),l(l),r(r),row(row),col(col){}
};
struct DLX // Dancing Link X
{
	int n,m,si;
	CLLNode a[MN];
	int r[MR],c[MC];
	int ansd,ans[MN];
	void init(int _n,int _m)
	{
		n=_n; m=_m; si=m+1;
		for(int i=0;i<=m;i++)
		{
			c[i]=0;
			a[i]=CLLNode(i,i,i-1,i+1);
		}
		a[m].r=0; a[0].l=m;
		for(int i=1;i<=n;i++)
			r[i]=-1;
	}
	void link(int R,int C)
	{
		c[C]++;
		if(r[R]<0)
		{
			r[R]=si;
			a[si]=CLLNode(c,a[C].d,si,si,R,C);
		}
		else
		{

			a[si]=CLLNode(c,a[C].d,c[R],a[c[R]].r,R,C);
		}
		si++;
	}
};

int main()
{
	return 0;
}