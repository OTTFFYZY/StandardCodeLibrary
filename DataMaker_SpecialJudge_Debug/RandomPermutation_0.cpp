#include <iostream>
#include <string.h>
#include <random>
#include <time.h>
#include <algorithm>
using namespace std;


const int M=1e5+5;
int per[M],ran[M];
bool cmp(int a,int b)
{
	return ran[a]<ran[b];
}
void randp(int n,int per[]) // generate random permutation of n elements
{
	for(int i=0;i<n;i++)
	{
		per[i]=i;
		ran[i]=rand()*rand();
	}
	sort(per,per+n,cmp);
}

int main()
{
	srand(time(0));
	int n=20;
	for(int t=0;t<5;t++)
	{
		randp(n,per);
		for(int i=0;i<n;i++)
			cout<<per[i]<<" ";
		cout<<endl;
	}

	n=50;
	randp(n,per);
	for(int i=0;i<n;i++)
		cout<<per[i]<<" ";
	cout<<endl;
	return 0;
}