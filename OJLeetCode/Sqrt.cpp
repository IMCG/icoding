/*Sqrt(x) */
//TLE   Last executed input:    2147395599
//error
class Solution {
public:
    int sqrt(int x) {
        if(x < 2)return x ;
        int l = 0,r = x/2;
        int m;
        while(l+1<r){
            m=(l+r)>>1;
            m*m>x?r=m:l=m;
        }
        return l;
    }
};
//AC
class Solution {
public:
    int sqrt(int x) {
        if (x < 2)return x;
        int l = 1, r = x / 2;
        int m;
        int mm;
        while (l<=r){
            m = (l + r) >> 1;
            if (x / m > m){
                l = m + 1;
                mm = m;
            }
            else if (x / m < m)
                r = m - 1;
            else
                return m;
        }
        return mm;
    }
};
//牛顿迭代法
class Solution {
public:
    int sqrt(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //每次取切线与x轴的交点
        double ans=x;
        while(abs(ans*ans-x)>0.00001)
        {
            ans=(ans+x/ans)/2;
        }
        return (int)ans;
    }
};