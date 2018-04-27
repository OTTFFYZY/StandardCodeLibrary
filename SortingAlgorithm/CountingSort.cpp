#include <iostream>
#include <string.h>
using namespace std;

const int M=1e5+5;
const int MN=1e5+5;
int a[M]={7,3,8,2,5,3,7};
int cnt[MN];
 //O(n+m) n is the number in a[]
 //       m is the range of a[]
void countingsort(int a[],int l,int r)
{
	memset(cnt,0,sizeof(cnt));
	for(int i=l;i<=r;i++)
		cnt[a[i]]++;
	int p=l;
	for(int i=0;i<MN;i++)
		while(cnt[i]--) a[p++]=i;
}

// sort node by a
struct Node
{
	int a,b;
	void show()
	{
		cout<<a<<" "<<b<<endl;
	}
}node[M],tmp[M];
void countingsort2(Node node[],int l,int r)
{
	memset(cnt,0,sizeof(cnt));
	for(int i=l;i<=r;i++)
		cnt[node[i].a]++;
	for(int i=1;i<MN;i++)
		cnt[i]+=cnt[i-1];
	for(int i=r;i>=l;i--)
		tmp[--cnt[node[i].a]]=node[i];
	for(int i=0;i<r-l+1;i++)
		node[i+l]=tmp[i];
}

int main()
{
	int n=7;
	countingsort(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;


	node[0].a=3; node[0].b=1;
	node[1].a=1; node[1].b=2;
	node[2].a=5; node[2].b=3;
	node[3].a=4; node[3].b=4;
	node[4].a=5; node[4].b=5;
	node[5].a=3; node[5].b=6;
	node[6].a=2; node[6].b=7;

	countingsort2(node,0,n-1);
	for(int i=0;i<n;i++)
		node[i].show();


	return 0;
}