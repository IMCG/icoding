//palindrome substring
string s;
char dp[5000][5001];
 
// Returns true if the substring [a, b) is palindrome.
bool isPalindrome(int a, int b)
{
    char & res = dp[a][b];
    if (res == -1) {
        if ( b - a  <= 1 ) {
            // string is empty or has one character, result is true
            res = true;
        } else {
            if (s[a] == s[b-1]) {
                res = isPalindrome(a + 1, b - 1);
            } else {
                res = false;
            }
        }
    }
    return res;
}
 
int count(string s) /* assume we already generated string s from S1 and S2 */
{
    this->s = s;
    int n = s.length();
    int res = 0;
     
    // For memoization, we fill dp[][] with -1.
    memset(dp, -1, sizeof(dp));
     
    // For each substring:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if ( isPalindrome(i,j) ) {
                res++;
            }
        }
    }
    return res;
}

//O(1)memory 再说吧
int count(string s)
{
    int n = s.length();
    int res = 0;
    // pick the middle point m:
    for (int m = 0; m < n; m++) {
        // Try an odd-length substring (even == 0), and also an even-length one (even == 1):
        for (int even = 0; even < 2; even++) {
            int i, j;
            // initialize pointers depending on even or not:
            bool pal = true;
            if (even == 1) {
                i = m;
                j = m + 1;
                res++;
            } else {
                i = m - 1;
                j = m + 1;
            }
            // do the check:
            while ( (i >= 0) && (j < n) ) {
                pal = (pal && (s[i] == s[j]) );
                if (pal) {
                    res++;
                }
                i--;
                j++;
            }
        }
    }
    return res;
}
