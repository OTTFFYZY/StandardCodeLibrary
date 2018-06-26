#include <iostream>
using namespace std;

typedef unsigned int UINT;

const UINT M=1e7;
const UINT MASK=32-1;
const UINT SHIFT=5; //2^5=32
UINT bitmap[(M>>SHIFT+1)+5];
UINT pri[M/10],npri=0;

inline void setbit(UINT n)
{
	bitmap[n>>SHIFT]|=1U<<(n&MASK);
}
inline bool getbit(UINT n)
{
	return bitmap[n>>SHIFT]&(1U<<(n&MASK));
}

int getpri()
{
	pri[npri++]=2;
    for(UINT i=3;i<M;i+=2)
        if(!getbit(i>>1))
        {
        	pri[npri++]=i;
        	for(UINT j=i*3;j<M;j+=2*i)
        		setbit(j>>1);
        }
    return npri;
}

bool ispri(int n)
{
	if(n<2) return 0;
	if(n==2) return 1;
	return getbit(n>>1);
}

int main()
{
	cout<<getpri()<<endl; //10^5 9592
						  //10^6 78498
						  //10^7 664579
						  //10^8 5761455
	return 0;
}