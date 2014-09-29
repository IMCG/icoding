//暴力搜索
//超时了
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
int n, sum;
bool solve(vector<int>arr,int sum){
	vector<int>cur(arr);
	vector<int>next;
	while (cur.size() != 1){
		for (int i = 0; i < (int)cur.size() - 1; ++i){
			next.push_back(cur[i] + cur[i + 1]);
		}
		swap(next, cur);
		next.clear();
	}
	return cur[0] == sum;
}
bool solve(vector<int>arr, int sum){
	vector<int>temp(arr);
	//good func
	for (int num = arr.size(); num>0; num--){
		for (int j = 0; j < num - 1; j++)
			temp[j] = temp[j] + temp[j + 1];
	}
	return temp[0] == sum;
}
void print(vector<int>arr){
	for (int i = 0; i < (int)arr.size(); ++i){
		if (i>0)
			cout << " ";
		cout << arr[i];
	}
	cout << "\n";
}
int main()
{
	while (cin >> n>> sum&&n){
		vector<int>arr(n);
		//good func
		//iota(arr.begin(), arr.end(), 1);
		for (int i = 0; i < (int)arr.size(); ++i)
			arr[i] = i + 1;
		do{
			if (solve(arr, sum)){
				print(arr);
				break;
			}
		}while(next_permutation(arr.begin(),arr.end()));
	}
	return 0;
}
//想象杨辉三角
//杨辉三角第n层第k个数记为Ckn那么=n!/[k!(n-k)!]=n * (n – 1)…*(n – k + 1) / k!
// 有了Ckn 那么即使题目中的初始数字不为1，只要乘上这个系数Ckn就行了。
//杨辉三角n行k个数字的值
int c(int n, int k)
{
    int result = 1;
    for (int i = 0; i < k; ++i)
    {
        result = result * (n - i) / (i + 1);
    }
 
    return result;
}
int main(int argc, char *argv[])
{
    int N, Sum;
    cin >> N >> Sum;
    int line[16];
    int i = 0;
    for (; i < N; ++i)
    {
        line[i] = i + 1;
    }
    do 
    {
        int result = 0;
        for (i = 0; i < N; ++i)
        {
            result += c(N - 1, i) * line[i];
        }
        if (result == Sum)
        {
            break;
        }
    } while (next_permutation(line, line + N));
    copy(line, line + N, ostream_iterator<int>(cout, " "));
    return 0;
}
