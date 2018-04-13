#include <iostream>
#include <algorithm>
using namespace std;

const int MB=8;
const int M=(1<<MB)+5;
const int INF=2e9+5;

int lg[M];
int st[M][M][MB];

void lg_init()
{
	lg[1]=0;
	for(int i=1;i<MB;i++)
		lg[1<<i]=1;
	for(int i=2;i<M;i++)
		lg[i]+=lg[i-1];
}

void rmq_init(int n,int m,int a[M][M]) //O(n*m*log(m))
{	
	for(int k=0;k<n;k++)
		for(int i=0;i<m;i++) 
			st[k][i][0]=a[k][i];
	for(int k=0;k<n;k++)
		for(int j=1;(1<<j)<=m;j++)
			for(int i=0;i+(1<<j)<=m;i++)
				st[k][i][j]=min(st[k][i][j-1],st[k][i+(1<<(j-1))][j-1]);
}
int rmq_min(int l1,int r1,int l2,int r2) //O(n)
{
	int j=lg[r2-l2+1];
	int ans=INF;
	for(int i=l1;i<=r1;i++)
		ans=min(ans,min(st[i][l2][j],st[i][r2-(1<<j)+1][j]));
	return ans;
}

int st2[M][MB][M][MB];
void rmq_init2(int n,int m,int a[M][M]) //O(n*log(n)*m*log(m))
{
	int i,j,k,l;
	for(k=0;(1<<k)<=n;k++)
	for(l=0;(1<<l)<=m;l++)
	for(i=0;i+(1<<k)<=n;i++)
	for(j=0;j+(1<<l)<=m;j++)
	{
		if(k==0&&l==0) st2[i][k][j][l]=a[i][j];
		else if(k==0) st2[i][k][j][l]=min(st2[i][k][j][l-1],st2[i][k][j+(1<<(l-1))][l-1]);
		else if(l==0) st2[i][k][j][l]=min(st2[i][k-1][j][l],st2[i+(1<<(k-1))][k-1][j][l]);
		else st2[i][k][j][l]=min(min(st2[i][k-1][j][l-1],
									 st2[i+(1<<(k-1))][k-1][j][l-1]),
			                     min(st2[i][k-1][j+(1<<(l-1))][l-1],
			                    	 st2[i+(1<<(k-1))][k-1][j+(1<<(l-1))][l-1]));
	}
}
void rmq_init21(int n,int m,int a[M][M])
{
	int i,j,k,l;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			st2[i][0][j][0]=a[i][j];
	for(k=0;k<=lg[n];k++)
	for(l=0;l<=lg[m];l++)
	{
		if(k+l)
			for(i=0;i+(1<<k)<=n;i++)
			for(j=0;j+(1<<l)<=m;j++)
			{
				if(k) st2[i][k][j][l]=min(st2[i][k-1][j][l],st2[i+(1<<(k-1))][k-1][j][l]);
				else st2[i][k][j][l]=min(st2[i][k][j][l-1],st2[i][k][j+(1<<(l-1))][l-1]);
			}
	}
}
int rmq_min2(int l1,int r1,int l2,int r2) //O(1)
{
	int k=lg[r1-l1+1],l=lg[r2-l2+1];
	return min(min(st2[l1][k][l2][l],
		           st2[r1-(1<<k)+1][k][l2][l]),
			   min(st2[l1][k][r2-(1<<l)+1][l],
			   	   st2[r1-(1<<k)+1][k][r2-(1<<l)+1][l]));
}


int main()
{
	return 0;
}