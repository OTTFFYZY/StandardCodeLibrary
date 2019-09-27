#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=1e5+5;
int a[M]={237625,325,325,4,21,41,51,5,532,35,325,32532523,12412515,352532,235325525,124,21,42141};

const int MB=16;
const int B=1<<16;
int cnt[B+5];
int tmp[M];
inline int getbase(int x,int i)
{
	return (x>>(MB*i))&(B-1);
}
void radix65536(int a[],int n) // positive
{
	for(int i=0;i<2;i++) // long long i<4
	{
		memset(cnt,0,sizeof(cnt));
		for(int j=0;j<n;j++) cnt[getbase(tmp[j]=a[j],i)]++;
		for(int j=1;j<B;j++) cnt[j]+=cnt[j-1];
		for(int j=n-1;j>=0;j--) a[--cnt[getbase(tmp[j],i)]]=tmp[j];
	}
}

int main()
{
	int n=18;
	radix65536(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}