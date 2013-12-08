//bitset
#include<iostream>
#include<bitset>
#include<cstddef>
using namespace std;

int main()
{
	//assign
	bitset<n> b;				//nλ0
	bitset<n> b(u);				//unsigned long
	bitset<n> b(s);				//string ����s�ĸ���
	bitset<n> b(s,pos��n);       //s��pos��ʼn������

	//�������
	/* b.any() �Ƿ������Ϊ1�Ķ�������?
	b.none()  ��������Ϊ1�Ķ���������
	b.count()  1�ĸ�����
	b.size()   �����Ƹ�����
	b[pos]     ����λ��
	b.test[pos]    pos �Ƿ�Ϊ1
	b.set()    ȫ��Ϊ1
	b.set[pos]   pos��1
	b.reset()  ȫ��0
	b.reset[pos]  pos��0
	b.flip()    ��λȡ��
	b.flip[pos]  pos ȡ��*/

	bitset<32> bitvec;
	bool is_set=bitvec.any();     //false
	bool is_not_set=bitvec.none();//true

	//conut����size_t  <cstddef>
	//size_t sz=bitvec.size();
	size_t bits_set=bitvec.count();//the number of 1

	//����bitset�е�λ
	for(int index=0;i!=32;index+=2)
		bitvec[index]=1;
	cout<<"bitvec"<<bitvec<<endl;
}