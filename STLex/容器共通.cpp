����һ��������Ԫ��Ϊ��ֵ����ɳ�ʼ��������
std::list<int> l;//l is a linked list of ints 
...
//copy all elements of the list as floats into a vector
std::vector<float> c(l.begin(),l.end());

����Ԫ��Ϊ��ֵ����ʼ��
int array[]={2,3,17,33,45,77};
...
//copy array into a set
std::set<int> c(array,array+sizeof��array��/sizeof(array[0]));

��׼����װ����ɳ�ʼ������
//read all integer elements of the deque from atandard input
std::deque<int> c((std::istream_iterator<int>(std::cin),
                  (std::istream_iterator<int>() ));

Assignments&swap()