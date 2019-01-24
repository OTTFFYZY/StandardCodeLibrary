#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef unsigned long long ULL;

const int MK=100;
const int MT=63;
ULL dp[MK+5][MT+5];
// dp[i][j] the highest floor that i eggs try j times
void init_dp()
{
	for(int i=1;i<=MK;i++)
		for(int j=1;j<=MT;j++)
			dp[i][j]=dp[i-1][j-1]+1+dp[i][j-1];
}
