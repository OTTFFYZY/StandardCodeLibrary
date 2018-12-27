#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

ifstream fin,myfin;

string s1,s2;

const char datamk[]="datamaker.exe > in.txt";
const char stdpro[]="stdprogram.exe < in.txt > stdout.txt";
const char mypro[]="myprogram.exe < in.txt > myout.txt";

int main()
{
	int f=1;
	while(f)
	{
		system(datamk);
		cout<<"ok0"<<endl;
		system(stdpro);
		cout<<"ok1"<<endl;
		system(mypro);
		cout<<"ok2"<<endl;

		fin.open("stdout.txt",ios::in);
		myfin.open("myout.txt",ios::in);

		int i=1;
		while(!fin.eof()||!myfin.eof())
		{
			if(fin.eof()||myfin.eof())
			{
				cout<<"eof WA!!!!!!"<<endl;
				f=0;
				break;
			}
			getline(fin,s1);
			getline(myfin,s2);
			//cout<<s1<<endl<<s2<<endl<<endl;
			if(s1!=s2)
			{
				cout<<"Line "<<i<<" WA!!!!!!"<<endl;
				f=0;
				break;
			}
			i++;
		}
		if(f)
			cout<<"AC!!!!!!"<<endl;

		fin.close();
		myfin.close();
		//f=0;
	}
	return 0;
}