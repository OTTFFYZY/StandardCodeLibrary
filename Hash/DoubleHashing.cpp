#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ULL;
const ULL MOD1=1e9+7;
const ULL MOD2=1e9+9;

pair<ULL,ULL> double_hashing(ULL val)
{
	return make_pair(val%MOD1,val%MOD2);
}

pair<ULL,ULL> string_double_hashing(char *str)
{
	ULL ch,h1=0,h2=0;
	while(ch=*str++)
	{
		h1=h1*MOD1+ch;
		h2=h2*MOD2+ch;
	}
	return make_pair(h1,h2);
}

int main()
{
	return 0;
}