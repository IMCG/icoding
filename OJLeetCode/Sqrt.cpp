/*Sqrt(x) */
class Solution {
public:
    int sqrt(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        double ans=x;
        while(abs(ans*ans-x)>0.00001)
        {
            ans=(ans+x/ans)/2;
        }
        return (int)ans;
    }
};