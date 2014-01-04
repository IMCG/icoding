/*Pow(x, n) */
class Solution {
public:
    double pow(double x, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n<0) return 1.0/power(x,-n);
        else return power(x,-n);
    }
    private:
    double power(double x,int n)
    {
        if(n==0) return 1;
        if(n%2==0)
          return power(x*x,n/2);
        else
          return power(x*x,n/2)*x;
    }
};