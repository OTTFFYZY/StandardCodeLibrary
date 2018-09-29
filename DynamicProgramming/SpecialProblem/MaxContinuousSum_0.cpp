#include <iostream>
using namespace std;

const int M=1e5+5;
int nu[M];

int maxsum(int n)
{
	int ans=INT_MIN,nsum=INT_MIN;
	for(int i=0;i<n;i++)
	{
		nsum=max(nsum+nu[i],nu[i]);
		ans=(ans,nsum);
	}
	return ans;
}

int main()
{
	return 0;
}