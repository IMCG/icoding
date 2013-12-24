/*Author:xuesen
*@Data:12/24
*@CS106_Streams
*/
#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>	//for setw()
#include<string>
#include<sstream>
#include<tchar.h>	//define _TEXT
using namespace std;
int main()
{
	//ifstream token(_TEXT("E:\\2.txt"));
	//To create an ifstream that reads from a file.
	ifstream myStream("myFile.txt");
	int myInteger;
	myStream>>myInteger;//Read an integer from myFile.txt
	//Notice that we worte myStream>>myInteger rather than ifstram>>myInteger

	//using the ifstream's open member function
	ifstream myStream;
	myStream.open("myFile.txt");
	if(!myStream.is_open())
		cerr<<"Couldn't open the file "<<endl;

	//when you create the ofstream,
	ofstream myStream("myFile.txt");

	//convert the string into a C_style 
	ifstream input(myStream.c_str());//open the filename stored in myString

	/*A Useful Shorthand :loop-and-a-half idiom*/
	while(true){
		int intValue;
		double doubleValue;
		myStream>>intValue>>doubleValue;

		if(myStream.fail()) break;
		/*.....process values here.....*/
	}
	//entirely equivalent
	int intValue;
	double doubleValue;
	while(myStream>>intValue>>doubleValue){
		/*.....process values hera.....*/
	}
	//
	string name;
	getline(cin,name);//a grat way

	/*A String Buffer:stringstream:BY the <sstream>*/
	
}
