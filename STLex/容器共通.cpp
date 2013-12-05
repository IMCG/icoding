以另一个容器的元素为初值，完成初始化操作：
std::list<int> l;//l is a linked list of ints 
...
//copy all elements of the list as floats into a vector
std::vector<float> c(l.begin(),l.end());

数组元素为初值，初始化
int array[]={2,3,17,33,45,77};
...
//copy array into a set
std::set<int> c(array,array+sizeof（array）/sizeof(array[0]));

标准输入装置完成初始化操作
//read all integer elements of the deque from atandard input
std::deque<int> c((std::istream_iterator<int>(std::cin),
                  (std::istream_iterator<int>() ));

Assignments&swap()