#include <iostream>
using namespace std;

const int M=1e6+5;

int isp[M],pri[M],npri=0;

//nlogn
void getpri0(int n)
{
	//isp[0]=isp[1]=1;
	for(int i=2;i<=n;i++)
		if(!isp[i])
		{
			pri[npri++]=i;
			for(int j=i+i;j<=n;j+=i)
				isp[j]=1;
		}
}

void getpri1(int n)
{
	//isp[0]=isp[1]=1;
	for(int i=2;i*i<=n;i++)    //i*i <=n <= INT_MAX
		if(!isp[i])
			for(int j=i*i;j<=n;j+=i) 
				isp[j]=1;
	for(int i=2;i<=n;i++)
		if(!isp[i]) pri[npri++]=i;
}

int main()
{
	getpri1(100);
	cout<<npri<<endl;

	npri=0;
	getpri0(1e6);
	cout<<npri<<endl;
	return 0;
}