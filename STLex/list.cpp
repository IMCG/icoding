#include<iostream>
#include<list>
#include<string>
#include<algorithm>
using namespace std;

void printlists(const list<int>&l1,const list<int>&l2)
{
	cout<<"list1:";
	copy(l1.begin(),l1.end(),
		ostream_iterator<int>(cout," "));
	cout<<endl;
	cout<<"list2:";
	copy(l2.begin(),l2.end(),
		ostream_iterator<int>(cout," "));
	cout<<endl<<endl;
}
int main()
{
	list<int> list1,list2;
	for(int i=0;i<6;++i)
	{
		list1.push_back(i);
		list2.push_front(i);
	}
	printlists(list1,list2);
	//splice's apply(destination->source)
	list2.splice(find(list2.begin(),list2.end(),
		        3),
				list1);
     printlists(list1,list2);
	 //move first element to the end
	 list2.splice(list2.end(),
		         list2,
				 list2.begin());
	 printlists(list1,list2);
	 list2.sort();
	 list1=list2;
	 list2.unique();
	 printlists(list1,list2);
	 list1.merge(list2);
	 printlists(list1,list2);
}