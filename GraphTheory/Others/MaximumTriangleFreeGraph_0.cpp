#include <bits\stdc++.h>
using namespace std;

const int M=105;

int main()
{
	int n; scanf("%d",&n);
	int l=n/2,r=(n+1)/2;
	printf("%d\n",l*r);
	for(int i=1;i<=l;i++)
		for(int j=l+1;j<=n;j++)
			printf("%d %d\n",i,j);
	return 0;
}