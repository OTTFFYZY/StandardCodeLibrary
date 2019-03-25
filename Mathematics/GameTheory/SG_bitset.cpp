#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int M=50;
const int MB=10;
typedef bitset<MB> BS; 
int mex(BS s)
{
	for(int i=0;i<MB;i++)
		if(!s[i]) return i;
	return MB;
}
int sg[M];
BS s[M];
void getsg()
{
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<i;j++) // some rules
			s[i].set(sg[j]);
		sg[i]=mex(s[i]);
	}
}

int main()
{
	return 0;
}