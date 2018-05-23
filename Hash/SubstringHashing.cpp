#include <iostream>
using namespace std;

typedef unsigned long long ULL;

const int M=1e5+5;
const ULL SEED=1e9+7;
const ULL MOD=1e9+9;

ULL h[M],seed[M]={1};
void hash_init(char str[])
{
	h[0]=0;
	ULL ch;
	for(int i=1;ch=*str++;i++)
	{
		h[i]=(h[i-1]*SEED+ch)%MOD;
		seed[i]=seed[i-1]*SEED;
	}
}

ULL hash_lr(int l,int r) //substring [l~r]
{
	return (h[r+1]-h[l]*seed[r-l+1]+MOD)%MOD;
}


int main()
{
	return 0;
}