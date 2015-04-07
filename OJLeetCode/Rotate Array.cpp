/*Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] 
is rotated to [5,6,7,1,2,3,4].*/
//AC
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k = k % n;
        std::rotate(nums, nums + n - k, nums + n);
    }
};
//AC
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k = k % n;
        reverse(nums,nums+n-k);
        reverse(nums+n-k,nums+n);
        reverse(nums,nums+n);
    }
};