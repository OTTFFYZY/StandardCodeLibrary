#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=1e3+5;

int bit0[M][M],bit1[M][M],bit2[M][M],bit3[M][M]; //Binary Index Tree
inline int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int y,int v) //add v at (x,y)
{
	for(int i=x;i<M;i+=lowbit(i))
		for(int j=y;j<M;j+=lowbit(j))
		{
			bit0[i][j]+=v; bit1[i][j]+=v*i;
			bit2[i][j]+=v*j; bit3[i][j]+=v*i*j;
		}
}
void init(int n,int m,int a[M][M])
{
	memset(bit0,0,sizeof(bit0));
	memset(bit1,0,sizeof(bit1));
	memset(bit2,0,sizeof(bit2));
	memset(bit3,0,sizeof(bit3));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			add(i,j,a[i][j]-a[i][j-1]-a[i-1][j]+a[i-1][j-1]);
}
void add(int stx,int sty,int edx,int edy,int v) //add v to (stx~edx,sty~edy)
{
	add(stx,sty,v);
	add(stx,edy+1,-v);
	add(edx+1,sty,-v);
	add(edx+1,edy+1,v);
}
int get_sum(int x,int y) //sum of a(1~x,1~y)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i))
		for(int j=y;j;j-=lowbit(j))
			ans+=bit0[i][j]*(x+1)*(y+1)
		        -bit1[i][j]*(y+1)
		        -bit2[i][j]*(x+1)
		        +bit3[i][j];
	return ans;
}
int get_sum(int stx,int sty,int edx,int edy) // sum of (stx~edx,sty~edy)
{
	return get_sum(edx,edy)-get_sum(stx-1,edy)-get_sum(edx,sty-1)+get_sum(stx-1,sty-1);
}

int main()
{
	return 0;
}