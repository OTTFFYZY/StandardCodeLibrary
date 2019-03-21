#include <iostream>
using namespace std;
int main()
{
	int n=20;
	// unordered
	for(int i=1;i<n;i++)
	{           
		int nu,tmp;
	    for(nu=i,tmp=i/10;tmp;tmp/=10) //odd length
	        nu=nu*10+tmp%10;
	    cout<<nu<<endl;
	    for(nu=i,tmp=i;tmp;tmp/=10)    //even length
	        nu=nu*10+tmp%10;
	    cout<<nu<<endl;
	}

	// ordered
	for(int i=1;i<1000;i*=10)
	{
		for(int j=i;j<i*10;j++)
		{
			int nu=j,tmp;
			for(tmp=j/10;tmp;tmp/=10)
				nu=nu*10+tmp%10;
			cout<<nu<<" ";
		}
		for(int j=i;j<i*10;j++)
		{
			int nu=j,tmp;
			for(tmp=j;tmp;tmp/=10)
				nu=nu*10+tmp%10;
			cout<<nu<<" ";
		}
	}
	return 0;
}
