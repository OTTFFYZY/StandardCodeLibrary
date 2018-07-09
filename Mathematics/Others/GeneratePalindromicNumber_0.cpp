#include <iostream>
using namespace std;
int main()
{
	int n=20;
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
	return 0;
}
