#include<iostream>
using namespace std;
class Time{
public:					//public interface
	
	void set()
	{
		cin>>hour>>minute>>sec;
	}
private:
	int hour;
	int minute;
	int sec;
};
int main()
{
	Time time;
	time.set();

	Time t,*p;
	p=&t;
	t.set();

	Time &b=time;     //ͨ��ָ�룬���ã���Ա��������ʶ���
	b.set();
	
	cout<<sizeof(Time)<<endl;			//12ȡ�������ݳ�Ա��ռ�Ŀռ䣬�޹غ���
}
//����
//int a;
//int &b=a; ����������Ϊһ��������һ������
//����������ֵ�&�����÷����������ǵ�ַ��
//
