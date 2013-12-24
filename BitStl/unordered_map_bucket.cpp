#include<iostream>
#include<unordered_map>
using namespace std;

typedef unordered_map<char,int> Mymap;
int main()
{
	Mymap c1;

	c1.insert(Mymap::value_type('a',1));
	c1.insert(Mymap::value_type('b',2));
	c1.insert(make_pair('c',3));
	c1.insert(Mymap::value_type('d',4));

    //display contents
	for(auto i=c1.begin();i!=c1.end();i++)
		cout<<i->first<<" "<<i->second<<endl;

	// inspect bucket containing 'a' 
    Mymap::const_local_iterator lit = c1.begin(c1.bucket('b')); 
     cout << " [" << lit->first << ", " << lit->second << "]"; 
	cout<<endl;
	// display buckets for keys 
    Mymap::size_type bs = c1.bucket('a'); 
     cout << "bucket('a') == " << bs <<  endl; 
     cout << "bucket_size(" << bs << ") == " << c1.bucket_size(bs) 
        <<  endl; 
 
	 // inspect current parameters 
     cout << "bucket_count() == " << c1.bucket_count() <<  endl; 
     cout << "load_factor() == " << c1.load_factor() <<  endl; 
     cout << "max_bucket_count() == " 
        << c1.max_bucket_count() <<  endl; 
     cout << "max_load_factor() == " 
        << c1.max_load_factor() <<  endl; 
     cout <<  endl; 
 
// change max_load_factor and redisplay 
    c1.max_load_factor(0.10f); 
     cout << "bucket_count() == " << c1.bucket_count() <<  endl; 
     cout << "load_factor() == " << c1.load_factor() <<  endl; 
     cout << "max_bucket_count() == " 
        << c1.max_bucket_count() <<  endl; 
     cout << "max_load_factor() == " 
        << c1.max_load_factor() <<  endl; 
     cout <<  endl; 
 
// rehash and redisplay 
    c1.rehash(100); 
     cout << "bucket_count() == " << c1.bucket_count() <<  endl; 
     cout << "load_factor() == " << c1.load_factor() <<  endl; 
     cout << "max_bucket_count() == " 
        << c1.max_bucket_count() <<  endl; 
     cout << "max_load_factor() == " 
        << c1.max_load_factor() <<  endl; 
     cout <<  endl; 
    return (0); 
   
	
}
		