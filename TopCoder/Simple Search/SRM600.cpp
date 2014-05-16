#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#include <cmath>
/*
    double 类型
    int a = (int)ceil(7 / 2.0);
    int b = (int)floor(7 / 2.0);
*/
class TheShuttles{
public:
    int getLeastCost(vector<int>cnt, int baseCost, int seatCost){
        int len = cnt.size();
        //int res = 1000000;
        int res = numeric_limits<int>::max();
        //枚举1-100个座位
        for (int i = 1; i <= 100; ++i){
            int s = 0;
            for (int j = 0; j < len; ++j){
               // s += cnt[j] / i + ((cnt[j] % i) != 0);
                //注意这个地方
                s += (cnt[j] + i - 1) / i;
            }
            int sum = s*(baseCost + i*seatCost);
            res = min(res, sum);
        }
        return res;
    }
};
//
int getLeastCost(vector<int> cnt, int baseCost, int seatCost)
{
    // initialize res with a big number. Since we know result fits a integer,
    // let's use the largest integer of them:
    int res = numeric_limits<int>::max();
    // For each number of seats x:
    for (int x = 1; x <= 100; x++) {
        // calculate number of shuttles
        int n = 0;
        for (int c: cnt) {
            //Fast ceiling of an integer division in C++
            // (c + (x - 1)) / x gives the ceil(c/x), c/x rounded up. Try it.
            n += (c + (x - 1) ) / x;
        }
        // and the cost
        int cost = n * baseCost + n * x * seatCost;
        // remember the minimum:
        res = std::min(res, cost);            
    }
    return res;
}