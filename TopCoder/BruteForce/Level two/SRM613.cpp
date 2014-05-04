//SRM 613 div2-500
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//可能有些tricky（只考虑了0为阈值的情况）
class TaroFriends{
public:
	int getNumber(vector<int>coordinates, int X)
	{
		transform(coordinates.begin(), coordinates.end(),
			coordinates.begin(), [&](int c){return c >= 0 ? c - X : c + X; });
		auto m = minmax_element(coordinates.begin(), coordinates.end());
		return abs(*m.second - *m.first);
	}
};
/*It often helps to analyze a problem in reverse. What matters in this problem is 
that after the moves, two cats will be the left-most and right-most ones. 
The final distance depends on those two cats. So we should focus on them.
考虑每对状态。
*/
int getNumber(vector<int> coordinates, int X)
{
    int n = coordinates.size();
    if (n == 1) {
        return 0;
    }
    int res = 2000000000;
    // for each pair of cats (i, j)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                // try each pair of directions (p,q)
                for (int p = -X; p <= X; p += 2*X) {
                    for (int q = -X; q <= X; q += 2*X) {
                        int a = coordinates[i] + p;
                        int b = coordinates[j] + q;
                        bool valid = (a <= b);
                        // For each of the other cats
                        for (int k = 0; k < n; k++) {
                            int r = coordinates[k];
                            if ( (i != k) && (j != k) ) {
                                // moving the cat in one of the directions
                                // should put it between [a,b].
                                valid &= ( (a <= r-X && r-X <= b) || (a <= r+X && r+X <= b) );
                            }
                        }
                        if (valid) {
                            res = std::min(res, b - a);
                        }
                        if (X == 0) { //need to handle this special case
                            break;
                        }
                    }
                    if (X == 0) { //same
                        break;
                    }
                }
            }
        }
    }
    return res;
}


//good practice

#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define SZ(x) (int)x.size()
#define fs first
#define sc second

//快速幂
int Pow(int B, int P){
	int R = 1;
	while (P > 0){
		if (P % 2 == 1)
			R *= B;
		P /= 2;
		B *= B;
	}
	return R;
}
int main()
{
	cout << Pow(2, 4) << " ";
}