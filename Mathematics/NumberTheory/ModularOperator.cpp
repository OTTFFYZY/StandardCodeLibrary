#include <iostream>
using namespace std;

typedef long long LL;

const int MOD=1e9+7;
template<typename T>
struct ModNum
{
	T a;
	ModNum(T a=0):a(a)
	{
		mod();
	}
	ModNum mod()
	{
		a=(a%MOD+MOD)%MOD;
		return *this;
	}
	ModNum operator+(const ModNum &B) const
	{
		return (a+B.a)%MOD;
	}
	ModNum operator-(const ModNum &B) const
	{
		return (a+MOD-B.a)%MOD;
	}
	ModNum operator*(const ModNum &B) const
	{
		//return (a*b)%MOD; if a,b is small
		ModNum ans=0,tmp=*this;
		T b=B.a;
		while(b)
		{
			if(b&1) ans=ans+tmp;
			tmp=tmp+tmp;
			b>>=1;
		}
		return ans;
	}
	ModNum operator^(const ModNum &B) const
	{
		ModNum ans=1,tmp=*this;
		T b=B.a;
		while(b)
		{
			if(b&1) ans=ans*tmp;
			tmp=tmp*tmp;
			b>>=1;
		}
		return ans;
	}
};

int main()
{
	return 0;
}