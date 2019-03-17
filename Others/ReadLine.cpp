#include <iostream>
#include <stdio.h>

const int M=1e5+5;
char s[M];

int readline(char *s)
{
	if(fgets(s,M,stdin)==EOF) return -1;
	int l=strlen(s);
	if(s[l-1]=='\n') s[--l]==' ';
	if(s[l-1]=='\r') s[--l]==' ';
	return l;
}

int main()
{
	return 0;
}