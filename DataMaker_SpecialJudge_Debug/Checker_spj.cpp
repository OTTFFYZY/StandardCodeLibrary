#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

ifstream fin,myfin;

string s1,s2;

const char datamk[]="datamaker.exe > in.txt";
const char mypro[]="myprogram.exe < in.txt > myout.txt";

int f=1;

bool check()
{
	//
}

void spj()
{
	while(!fin.eof()||!myfin.eof())
	{
		if(fin.eof()||myfin.eof())
		{
			cout<< "WA EOF!" <<endl;
			f=0;
			return;
		}
		if(!check()) return 0;
	}
	return 1;
}

int main()
{
	while(f)
	{
		system(datamk);
		cout<<"ok0"<<endl;
		system(mypro);
		cout<<"ok1"<<endl;

		fin,open("in.txt",ios::in);
		myfin.open("myout.txt",ios::in);
		int i=1;
		spj();
		if(f)
			cout<<"AC!!!!!!"<<endl;
		fin.close();
		myfin.close();
		//f=0;
	}
	return 0;
}