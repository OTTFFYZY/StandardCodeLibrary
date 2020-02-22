#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=1e6+5;

int insertSort(int v[],int l,int r)
{
	int tmp,j;
	for(int i=l+1;i<r;i++)
	{
		tmp=v[i];
		for(j=i-1;j>=l&&v[j]>tmp;j--)
			v[j+1]=v[j];
		v[j+1]=tmp;
	}
	return (r+l)>>1;
}

int BFPRT(int v[],int l,int r,int k);

int pivot(int v[],int l,int r)
{
	if(r-l<5)
		return insertSort(v,l,r);
	int subr=l-1;
	for(int i=l;i+4<=r;i+=5)
	{
		int id=insertSort(v,i,i+4);
		swap(v[++subr],v[id]);
	}
	return BFPRT(v,l,subr,(subr-l+1)/2+1);
}

int partition(int v[],int l,int r,int pid)
{
	swap(v[pid],v[r]);
	pid=l;
	for(int i=l;i<r;i++)
	{
		if(v[i]<v[r])
			swap(v[pid++],v[i]);
	}
	swap(v[pid],v[r]);
	return pid;
}

// k in [1 ~ r-l+1]
int BFPRT(int v[],int l,int r,int k)
{
	int pid=pivot(v,l,r);
	pid=partition(v,l,r,pid);
	int n=pid-l+1;
	if(n==k) return pid;
	if(n>k)
		return BFPRT(v,l,pid-1,k);
	else
		return BFPRT(v,pid+1,r,k-n);
}

int main(int argc, char const *argv[])
{
	int k=5;
	int v[10]={9,1,2,3,1,5,-1,8,7,-10};
	int pid=BFPRT(v,0,9,k);
	cout<<v[pid]<<endl;
	for(int i=0;i<10;i++)
		cout<<v[i]<<" ";
	cout<<endl;
	return 0;
}