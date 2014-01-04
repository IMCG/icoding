/*Search in Rotated Sorted Array II 
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/
class Solution {
public:
    bool search(int A[], int n, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int first=0;
        int last=n;
        while(first!=last)
        {
            int mid=(first+last)/2;
            if(A[mid]==target)
              return true;
            if(A[first]<A[mid])
             {
                 if(A[first]<=target && target <A[mid])
                   last=mid;
                 else
                   first=mid+1;
             }
            else if(A[first]>A[mid])
            {
                if(A[mid]<target && target<=A[last-1])
                   first=mid+1;
                else
                   last=mid;
            }else
               first++;
        }
        return false;
    }
};