#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=1e3+5;

//2d Range add Single Point Query
int bit[M][M];//Binary Index Tree
inline int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int y,int v)
{
	for(;x<M;x+=lowbit(x))
		for(int j=y;j<M;j+=lowbit(j))
			bit[x][j]+=v;
}
void init(int n,int m,int a[M][M])
{
	memset(bit,0,sizeof(bit));
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
int get_v(int x,int y) //value of a(x,y)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i))
		for(int j=y;j;j-=lowbit(j))
			ans+=bit[i][j];
	return ans;
}

int main()
{
	return 0;
}