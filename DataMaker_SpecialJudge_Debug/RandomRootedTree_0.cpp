#include <iostream>
#include <random>
#include <algorithm>
#include <time.h>
using  namespace std;

int main()
{
	srand(time(0));
	int n=50;
	for(int i=1;i<=n;i++)
		cout<<i<<" "<<rand()%i<<endl;
	return 0;
}
