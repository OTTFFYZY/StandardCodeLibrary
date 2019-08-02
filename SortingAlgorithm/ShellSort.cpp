#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=1e5+5;

int a[M]={7,3,8,2,5,3,7};

void shell_sort(int a[],int n)
{
	int h=1;
	while(h<n/3) h=h*3+1; // 1 4 13 40 121 364 ...
	while(h>=1)
	{
		for(int i=h;i<n;i++)
		{
			int tmp=a[i];
			int j=i;
			for(;j>=h && tmp<a[j-h];j-=h)
				a[j]=a[j-h];
			a[j]=tmp;
		}
		h=h/3;
	}
}


int main()
{
	int n=7;
	shell_sort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;

	return 0;
}