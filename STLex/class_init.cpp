//
class Solution{
private:
	int a;
	int b;
public:
    Solution:a(1),b(2){}
	Solution(int a,int b)
	{
		this->a=a;
		this->b=b;
	}
	int getA()
	{
		return this->a;
	}
	int getB()
	{
		return this->b;
	}
};