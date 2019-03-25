#include <iostream>
using namespace std;

const int M;
int a[M];
int n;
bool win()
{
	int ans=0;
	for(int i=1;i<n;i+=2)
		ans^=a[i];
	return ans;
}