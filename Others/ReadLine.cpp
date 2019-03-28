#include <iostream>
#include <stdio.h>

const int M=1e5+5;
char s[M];

int readline(char *s)
{
	if(fgets(s,M,stdin)==NULL) return EOF;
	int l=strlen(s);
	if(s[l-1]=='\n') s[--l]='\0';
	if(s[l-1]=='\r') s[--l]='\0';
	return l;
}

int main()
{
	return 0;
}