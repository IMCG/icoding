//Reflect-and-prefix method
//递归地从n-1比特的格雷码生成
//参考wiki上的定义
class Solution{
 public:
 	vector<int> grayCode(int n){
 		vector<int> result;
 		result.push_back(0);
 		for (int i = 0; i < n; ++i)
 		{
 			const int highest_bit = 1<<i;
 			for (int j = result.size()-1; j >= 0; j--)
 			{
 				//反着遍历才能对称。
 				result.push_back(highest_bit|result[j]);
 			}
 		}
 		return result;
 	}
};
//数学公式
class Solution{
 public:
 	vector<int> grayCode(int n){
 		vector<int>result;
 		const size_t size =1<<n;
 		result.reserve(size);
 		for (size_t i = 0; i < size; ++i)
 		{
 			result.push_back(binary_to_gray(i));
 		}
 		return result;
 	}
 private:
 	static unsigned int binary_to_gray(unsigned int n){
 		return n^(n>>1);
 	}
 	static unsigned int gray_to_binary(unsigned int g){
 		for(unsigned int mask=g>>1;mask!=0;mask=mask>>1)
 			g=g^mask;
 		return g;
 	}
};