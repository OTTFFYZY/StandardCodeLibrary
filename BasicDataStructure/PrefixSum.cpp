#include <stdio.h>
#include <string.h>

const int M=1e5+5;
int a[M],sum[M],n;
void init()
{
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
}
int getsum(int l,int r)
{
	return sum[r]-sum[l-1];
}


int b[M],n2;
void init2()
{
	memset(b,0,sizeof(b));
}
int add(int l,int r,int v) // add v to l~r
{
	b[l]+=v; b[r+1]-=v;
}
void getval()
{
	for(int i=1;i<=n2;i++)
		b[i]+=b[i-1];
}

int main()
{
	return 0;
}