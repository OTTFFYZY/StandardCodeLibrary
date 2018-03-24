#include <iostream>
#include <algorithm>
using namespace std;
const int M=20;

int lg[1<<M];
int st[1<<M][M];

void lg_init()
{
	lg[1]=0;
	for(int i=1;i<M;i++)
		lg[1<<i]=1;
	for(int i=2;i<(1<<M);i++)
		lg[i]+=lg[i-1];
}
void rmq_init(int n,int a[])
{	
	for(int i=0;i<n;i++) st[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=0;i+(1<<j)<=n;i++)
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int rmq_min(int l,int r)
{
	int j=lg[r-l+1];
	return min(st[l][j],st[r-(1<<j)+1][j]);
}

int main()
{
	return 0;
}