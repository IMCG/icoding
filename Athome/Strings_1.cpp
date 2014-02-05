//通过命令行参数产生一个临时文件名
#include<iostream>
#include<string>
using namespace std;
int main(int argc, char*argv[])
{//通过命令行参数产生一个临时文件名
#include<iostream>
#include<string>
using namespace std;
int main(int argc, char*argv[])
{
	string filename, basename, extname, tmpname;
	const string suffix("tmp");

	/*for each command-line argument
	(which is an ordinary C-string)*/
	for (int i = 0; i < argc; ++i){
		//proces argument as file name
		filename = argv[i];
		//search period in file name
		size_t idx = filename.find('.');
		if (idx == string::npos){
			//file name does not contain any period
			tmpname = filename + '.' + suffix;
		}
		else{
			//split file name into basename and extname
			basename = filename.substr(0,idx);
			extname = filename.substr(idx + 1);
			if (extname.empty()){
				tmpname = filename;
				tmpname += suffix;
			}
			else if(extname==suffix){
				tmpname = filename;
				tmpname.replace(idx + 1, extname.size(), "xxx");
			}
			else{
				tmpname = filename;
				tmpname.replace(idx + 1, string::npos, suffix);
			}
		}
		//print file name and temporary name
		cout << filename << "=>" << tmpname << endl;
	}
}
	string filename, basename, extname, tmpname;
	const string suffix("tmp");

	/*for each command-line argument
	(which is an ordinary C-string)*/
	for (int i = 0; i < argc; ++i){
		//proces argument as file name
		filename = argv[i];
		//search period in file name
		size_t idx = filename.find('.');
		if (idx == string::npos){
			//file name does not contain any period
			tmpname = filename + '.' + suffix;
		}
		else{
			//split file name into basename and extname
			basename = filename.substr(0,idx);
			extname = filename.substr(idx + 1);
			if (extname.empty()){
				tmpname = filename;
				tmpname += suffix;
			}
			else if(extname==suffix){
				tmpname = filename;
				tmpname.replace(idx + 1, extname.size(), "xxx");
			}
			else{
				tmpname = filename;
				tmpname.replace(idx + 1, string::npos, suffix);
			}
		}
		//print file name and temporary name
		cout << filename << "=>" << tmpname << endl;
	}
}