#include <iostream>
#include <stdio.h>
#include <bitset>
#include <algorithm>

using namespace std;

bitset<20> b;

int main()
{
	cout<<b.count()<<" "<<b.any()<<" "<<b.none()<<endl;
	cout<<b[3]<<endl;
	cout<<b.to_string()<<endl<<endl;

	b.set();
	cout<<b.count()<<" "<<b.any()<<" "<<b.none()<<endl;
	cout<<b.to_string()<<endl<<endl;
	
	b[3]=b[5]=0;
	b.reset(7);
	cout<<b.count()<<" "<<b.any()<<" "<<b.none()<<endl;
	cout<<b.to_string()<<endl<<endl;

	b.flip();
	b.set(9);
	cout<<b.count()<<" "<<b.any()<<" "<<b.none()<<endl;
	cout<<b.to_string()<<endl<<endl;

	b.reset();
	b.flip(0);
	cout<<b.count()<<" "<<b.any()<<" "<<b.none()<<endl;
	cout<<b.to_string()<<endl<<endl;

	bitset<20> c(b);
	c.set(7);
	cout<<c.to_ulong()<<endl;

	b.set(5);
	cout<<b.to_string()<<endl<<c.to_string()<<endl;
	cout<<(b|c).to_string()<<endl<<endl;
	cout<<b.to_string()<<endl<<c.to_string()<<endl;
	cout<<(b^c).to_string()<<endl<<endl;
	cout<<b.to_string()<<endl<<c.to_string()<<endl;
	cout<<(b&c).to_string()<<endl<<endl;
	cout<<b.to_string()<<endl;
	cout<<(~b).to_string()<<endl<<endl;
	cout<<b.to_string()<<endl;
	cout<<(b<<2).to_string()<<endl<<endl;
	cout<<b.to_string()<<endl;
	cout<<(b>>2).to_string()<<endl<<endl;

	cout<<(b==c)<<endl;



	return 0;
}