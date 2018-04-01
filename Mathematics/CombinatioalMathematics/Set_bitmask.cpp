#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int A,B; long long C; //set
	int c;
	A|=1<<c;            //insert c (c = 0~31)
	A&=~(1<<c);
	A^=1<<c;            //erase c (c = 0~31)
	a&(-a);             //the minimum element of A
	A=0;                //empty set
	A|B;                //union
	A&B;				//intersection
	int si=15;          //size of set
	int All=(1<<si)-1;  //universal set
	ALL^A;              //complementary set of A
	(A&B)==B;     	    //B is A's subset

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

	//
}