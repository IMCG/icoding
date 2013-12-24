// std_tr1__unordered_map__unordered_map_begin.cpp 
// compile with: /EHsc 
#include <unordered_map> 
#include <iostream> 
 
typedef std::unordered_map<char, int> Mymap; 
int main() 
    { 
    Mymap c1; 
 
    c1.insert(Mymap::value_type('a', 1)); 
    c1.insert(Mymap::value_type('b', 2)); 
    c1.insert(Mymap::value_type('c', 3)); 
 
// display contents " [c 3] [b 2] [a 1]" 
    for (Mymap::const_iterator it = c1.begin(); 
        it != c1.end(); ++it) 
        std::cout << " [" << it->first << ", " << it->second << "]"; 
    std::cout << std::endl; 
 
// inspect first two items " [c 3] [b 2]" 
    Mymap::iterator it2 = c1.begin(); 
    std::cout << " [" << it2->first << ", " << it2->second << "]"; 
    ++it2; 
    std::cout << " [" << it2->first << ", " << it2->second << "]"; 
    std::cout << std::endl; 
 
// inspect bucket containing 'a' 
    Mymap::const_local_iterator lit = c1.begin(c1.bucket('a')); 
    std::cout << " [" << lit->first << ", " << lit->second << "]"; 
 
    return (0); 
    } 