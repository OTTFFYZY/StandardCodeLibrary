#include <iostream>
#include <stdio.h>
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

    cout<<"abc"+a+b<<endl;
    a+=b+"cdcd";
    cout<<a<<endl<<endl;

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

    double db=3.1415926L;
    string num1=to_string(db),num2=to_string(12345);
    cout<<num1<<" "<<num2<<endl<<endl;
    printf("%.10f  %s\n",db,num1.c_str());
    double nu1=stod(num1);          //stof stold
    int nu2=stoi(num2);             //stol stoll stoull
    cout<<nu1<<" "<<nu2<<endl<<endl;

    double f1=23.43;
    double f2=1e-9;
    double f3=1e40;
    double f4=1e-40;
    double f5=123456789;
    string f_str1=std::to_string(f1);
    string f_str2=std::to_string(f2); // Note: returns "0.000000"
    string f_str3=std::to_string(f3); // Note: Does not return "1e+40".
    string f_str4=std::to_string(f4); // Note: returns "0.000000"
    string f_str5=std::to_string(f5);
    cout<<"std::cout: "<<f1<<'\n'
        <<"to_string: "<<f_str1<<"\n\n"
        <<"std::cout: "<<f2<<'\n'
        <<"to_string: "<<f_str2<<"\n\n"
        <<"std::cout: "<<f3<<'\n'
        <<"to_string: "<<f_str3<<"\n\n"
        <<"std::cout: "<<f4<<'\n'
        <<"to_string: "<<f_str4<<"\n\n"
        <<"std::cout: "<<f5<<'\n'
        <<"to_string: "<<f_str5<<'\n';

	return 0;
}