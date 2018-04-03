#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

// find the number of trailing zeros in 32-bit v
// 0x077CB531U -> 00000111011111001011010100110001
static const int MultiplyDeBruijnBitPosition[32] =
{
  0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8,
  31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9
};
int trail0(unsigned int v)
{ 
	return MultiplyDeBruijnBitPosition[((uint32_t)((v&-v)*0x077CB531U))>>27];
}

//find the number of leading zeros in 32-bit v
int lead0(unsigned x)
{
   if(x==0) return 32;
   int n=1;
   if((x>>16)==0){n=n+16; x=x<<16;}
   if((x>>24)==0){n=n+ 8; x=x<< 8;}
   if((x>>28)==0){n=n+ 4; x=x<< 4;}
   if((x>>30)==0){n=n+ 2; x=x<< 2;}
   n=n-(x>>31);
   return n;
}

//count 1


// find the lowest 1 and highest 1
inline int lowbit(int x)
{
	return x&(-x);
}
inline int highbit(int x)
{
    int p = low_bit(x);
    while (p != x) x -= p, p = low_bit(x);
    return p;
}

int only1(int x)  // x is the power of 2
{
	return v&&!v&(v-1);
}

int main()
{
	int A,B; long long C; //set
	int c;
	A|=1<<c;            //insert c (c = 0~31)
	A&=~(1<<c);
	A^=1<<c;            //erase c (c = 0~31)
	a&(-a);             //lowbit of A
	A=0;                //empty set
	A|B;                //union
	A&B;				//intersection
	int si=15;          //size of set
	int All=(1<<si)-1;  //universal set
	ALL^A;              //complementary set of A
	(A&B)==B;     	    //B is A's subset

	//enumerate the k-subset of ALL
	int k=2;
	int ksubset=(1<<k)-1;
	while(ksubset<=ALL)
	{
		//do something
		int x=ksubset&(-ksubset),y=ksubset+x;
		ksubset=((k&~y)/x>>1)|y;
	}

	//enumerate the subset of ALL
	for(int i=0;i<ALL;i++)
		;

	//enumerate the nonempty proper subset of A
	for(int subset=(A-1)&A;subset;subset=(subset-1)&A)
		;

	//enumerate the subset of A
	int subset=A;
	do
	{
		//do something
		subset=(subset-1)&A;
	}while(subset!=A)

	//count the number of element in A
	int cnt=0;
	for(int i=0;i<si;i++)
		if(A&(1<<i)) cnt++;
	cnt;
	//or
	for(int i=A;i;i>>=1)
		cnt+=i&1;

	//
}