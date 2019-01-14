#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int M=1e5+5;
char buf[M];

int main()
{
	int v;
	gets(buf);
	char *p=strtok(buf," ");
	while(p)
	{
		sscanf(p,"%d",&v);
		p=strtok(NULL," ");
		cout<<v<<endl;	
	}
	return 0;
}
