//返回arr中所有元素之和
//不需要main函数!
int arrSum(const vector<int> &arr) {
    return accumulate(arr.begin(), arr.end(), 0);
}