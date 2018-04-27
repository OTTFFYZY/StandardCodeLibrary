#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=1e5+5;

int a[M]={7,3,8,2,5,3,7};

void insertion_sort(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		int tmp=a[i],j=i-1;
		while(j>=0&&a[j]>tmp)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=tmp;
	}
}


int main()
{
	int n=7;
	insertion_sort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;


	return 0;
}