#include <iostream>
#include <string>
#include <string.h>
using namespace std;

char ss[]="dlrow,olleH";

int main()
{
	string a="Hello,world";
	string b(ss);
	cout<<a.length()<<endl;
	cout<<a<<endl<<b<<endl<<a[5]<<endl<<endl;

	a.append(2,'!');
	cout<<a<<endl<<endl;

	string c,d="abcdefg";
	c.assign(d,3,2);
	cout<<c<<endl<<endl;

	printf("%s\n\n",a.c_str());

	string e="aaaa",f="abc";
	cout<<(e<d)<<" "<<(f>d)<<" "<<(e==f)<<endl<<endl;

	string s("So, you like donuts, eh? Well, have all the donuts in the world!");
    cout<<"The original string is '"<<s<<"'"<<endl;          
    s.erase( 50, 14 );
    cout<<"Now the string is '"<<s<<"'"<<endl;
    s.erase( 24 );
    cout<<"Now the string is '"<<s<<"'"<<endl;
    s.erase();
    cout<<"Now the string is '"<<s<<"'"<<endl<<endl;  

    //returns the first occurrence of str within the current string, 
    //starting at index, string::npos if nothing is found, 
    string str1( "Alpha Beta Gamma Delta" );
   	string::size_type loc=str1.find("Omega",0);
   	if(loc!=string::npos)
     	cout<<"Found Omega at "<<loc<<endl;
 	else
    	cout<<"Didn't find Omega"<<endl;
    cout<<str1.rfind("a")<<endl;
    cout<<endl;

    //returns the index of the first character within the current string 
    //that does not match any character in str, beginning the search at index, 
    //string::npos if nothing is found, 
    cout<<str1.find_first_of("abc")<<endl;
    cout<<str1.find_first_not_of("ABC",3)<<endl;
    cout<<str1.find_last_of("abc")<<endl;
    cout<<str1.find_last_not_of("ABC",3)<<endl;
    cout<<endl;

    string s3="They say he carved it himself...from a BIGGER spoon";
    string s2="find your soul-mate, Homer.";
    s3.replace(32,s2.length(),s2);
    cout<<s3<<endl<<endl;

    string sub=s3.substr(10,5);
    cout<<sub<<endl<<endl;

	return 0;
}