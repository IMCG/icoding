//Copy map values to vector in STL
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

//@  迭代模式
//可以用auto关键字 直接迭代
template <typename M, typename V> 
void MapToVec( const  M & m, V & v ) {
    for( typename M::const_iterator it = m.begin(); it != m.end(); ++it ) {
    	v.push_back( it->second );
    }
}

//@ 区间模式
template< typename tPair >
struct second_t {
	typename tPair::second_type operator()(const tPair& p) const { return     p.second; }
};

template< typename tMap >
second_t< typename tMap::value_type > second(const tMap& m) { 
	return second_t<     typename tMap::value_type >(); 
}


int main() {
	std::map<int, bool> m;
	m[0] = true;
	m[1] = false;
	//...
	std::vector<bool> v;
	std::transform(m.begin(), m.end(), std::back_inserter(v), second(m));
	std::transform(m.begin(), m.end(), std::ostream_iterator<bool>(std::cout, ";"), second(m));
}

//@bind  绑定器
void main()
{
	typedef std::map<std::string, int> MapT;
	typedef std::vector<int> VecT;
	MapT map;
	VecT vec;

	map["one"] = 1;
	map["two"] = 2;
	map["three"] = 3;
	map["four"] = 4;
	map["five"] = 5;

	std::transform(map.begin(), map.end(),
		std::back_inserter(vec),	//good，因为未分配  
		std::bind(&MapT::value_type::second, std::placeholders::_1));	
}

//@[](){}  注意value_type  ...
std::transform(map.begin(), map.end(),
		std::back_inserter(vec),
		[](MapT::value_type& m){return m.second; });

