#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int a[10]={1,7,3,25,6,13,3,8,3,7};

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	cout<<max(1,3)<<" "<<min(1,3)<<endl<<endl;

	vector<int> vec;
	for(int i=0;i<10;i++)
		vec.push_back(100-i);
	sort(vec.begin(),vec.end());
	stable_sort(vec.begin(),vec.end());

	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	sort(a,a+10,cmp);
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	sort(a,a+10);
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl<<endl;


	cout<<lower_bound(a,a+10,4)-a<<endl;
	cout<<upper_bound(a,a+10,4)-a<<endl;
	cout<<lower_bound(a,a+10,3)-a<<endl;
	cout<<upper_bound(a,a+10,3)-a<<endl<<endl;
	
	int n=unique(a,a+10)-a;
	cout<<n<<endl;
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl<<endl;

	int ia=3,ib=5;
	swap(ia,ib); cout<<ia<<" "<<ib<<endl<<endl;

	

	int b[3]={1,2,3};
	do
	{
		for(int i=0;i<3;i++)
			cout<<b[i]<<" ";
		cout<<endl;
	}while(next_permutation(b,b+3));
	cout<<endl;
	do
	{
		for(int i=0;i<3;i++)
			cout<<b[i]<<" ";
		cout<<endl;
	}while(prev_permutation(b,b+3));
	cout<<endl;
	b[0]=3; b[1]=2; b[2]=1;
	do
	{
		for(int i=0;i<3;i++)
			cout<<b[i]<<" ";
		cout<<endl;
	}while(prev_permutation(b,b+3));
	cout<<endl;

	int c[10]={27,13,26,15,19,11,99,102,2,98};
	nth_element(c,c+3,c+10);
	for(int i=0;i<10;i++)
		cout<<c[i]<<" ";
	cout<<endl;

	nth_element(c,c+7,c+10);
	for(int i=0;i<10;i++)
		cout<<c[i]<<" ";
	cout<<endl;

	return 0;
}