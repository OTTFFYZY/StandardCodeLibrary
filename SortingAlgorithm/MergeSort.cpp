#include <iostream>
using namespace std;

const int M=1e5+5;
int a[M]={7,3,8,2,5};
int tmp[M];

void merge(int *l,int *m,int *r)
{
	int *p1=l,*p2=m+1; int k=0;
	while(p1<=m||p2<=r)
	{
		if(p1>m||p2<=r&&*p1>*p2)
		{
			tmp[k++]=*p2;
			p2++;
		}
		else
		{
			tmp[k++]=*p1;
			p1++;
		}
	}
	p1=l;
	for(int i=0;i<k;i++)
	{
		*p1=tmp[i];
		p1++;
	}
}
void merge_sort(int *l,int *r)
{
	if(l==r) return;
	int *mid=l+(r-l)/2;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	merge(l,mid,r);
}

int main()
{
	int n=5;
	//cin>>n;
	//for(int i=0;i<n;i++)
	//	cin>>a[i];
	merge_sort(a,a+n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}