#include <iostream>
#include <algorithm>
using namespace std;

void gnome_sort(int a[],int n)
{
	int i=1;
	while(i<n)
	{
		if(a[i-1]<=a[i]) i++;
		else
		{
			swap(a[i-1],a[i]);
			--i;
		}
	}
}

int a[10]={13,5,2,4,1,2,45,2,1,5};

int main()
{
	gnome_sort(a,10);
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}