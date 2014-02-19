//贪心算法，
//每个容器的面积，取决于最短的木板。(思维误区，这里不是梯形)
class Solution {
public:
    int maxArea(vector<int> &height) {
        int start = 0;
        int end = height.size()-1;
        int result = INT_MIN;
        
        while(start<end){
            int area=min(height[end],height[start])*(end-start);
            result=max(result,area);
            if(height[start] <= height[end]){
                start++;
            }else{
                end--;
            }
        }、
        return result;
    }
};
class Solution {
public:
    int maxArea(vector<int> &height) {
        int res = 0;
        int l = 0, r = height.size()-1;
        while (l < r)
        {
            if (height[l] <= height[r])
            {
                res = max(res, (r-l) * height[l]);
                l++;
            }
            else
            {
                res = max(res, (r-l) * height[r]);
                r--;
            }
        }
        return res;
    }
};