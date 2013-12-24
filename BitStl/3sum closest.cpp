class Solution {  
public:  
    int threeSumClosest(vector<int> &num, int target) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        int ret;  
        int magin=INT_MAX;  
        sort(num.begin(),num.end());  
        for(int i = 0 ; i < num.size(); i++ ){  
            if( i > 0 && num[i-1] == num[i] )  
                continue;  
            int j = i + 1;  
            int k = num.size() - 1;  
            while(j<k){  
                if( j > i + 1 && num[j] == num[j-1]){  
                    j++;  
                    continue;  
                }  
                if( k< num.size() - 1 && num[k] == num[k+1]){  
                    k--;  
                    continue;  
                }  
                int sum = num[i]+num[j]+num[k];  
                if(abs(sum-target)<magin){  
                    magin=abs(sum-target);  
                    ret=sum;  
                }  
                if(sum>target){  
                        k--;  
                }else{  
                        j++;                      
                }  
            }//while  
        }//for  
        return ret;  
    }  
};    