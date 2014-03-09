/*Given a string S and a string T, find the minimum window in S which will contain all the 
characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only 
one unique minimum window in S.
*/
//超时  好像可以用尺规法
class Solution {
public:
    string minWindow(string S, string T) {
        if (S.length() == 0 || T.length()==0)
			return "";
		if (S.find(T) != S.npos)
			return T;
		const int m = S.length();
		const int n = T.length();
		sort(T.begin(), T.end());
		int minWindow = INT_MAX;
		string result;
		for (int i = 0; i < m; i++){
			for (int j = i + n; j < m; j++){
				string tmp = S.substr(i, j - i + 1);
				sort(tmp.begin(), tmp.end());
				if (tmp.find(T) != tmp.npos && (int)tmp.length()<minWindow){
					minWindow = tmp.length();
					result = S.substr(i, j - i + 1);
				}
			}
		}
		return result;
    }
};
//哈希表 记录是否发现
class Solution {
public:
    string minWindow(string S, string T) {
        int N = S.size(), M = T.size();
        if (N < M) return "";
        int need[256] = {0};
        int find[256] = {0};
        for (int i = 0; i < M; ++i)
            need[T[i]]++;

        int count = 0, resStart = -1, resEnd = N;
        for (int start = 0, end = 0; end < N; ++end)
        {
            if (need[S[end]] == 0)
                continue;
            if (find[S[end]] < need[S[end]])
                count++;
            find[S[end]]++;
            if (count != M) continue;
            // move 'start'
            for (; start < end; ++start) {
                if (need[S[start]] == 0) continue;
                if (find[S[start]] <= need[S[start]]) break;
                find[S[start]]--;
            }
            // update result
            if (end - start < resEnd - resStart) {
                resStart = start;
                resEnd = end;
            }
        }
        return (resStart == -1) ? "" : S.substr(resStart, resEnd - resStart + 1);
    }
};
//尺规法 还需改正
class Solution {
public:
	string minWindow(string S, string T) {
		if (S.length() == 0 || T.length()==0)
			return "";
		if (S.find(T) != S.npos)
			return T;
		const int m = S.length();
		const int n = T.length();
		sort(T.begin(), T.end());
		int minWindow = INT_MAX;
		string result;
		//for (;;){
			int i = 0, j = n - 1;
			while (j <= m){
				while (j - i + 1 < n)
					j++;
				string tmp = S.substr(i, j - i + 1);
				string copy(tmp);
				sort(copy.begin(), copy.end());
				if (copy.find(T) != S.npos ){
					i++;
					if (copy.length() < minWindow){
						result = tmp;
						minWindow = copy.length();
						//i++;
					}
				}
				else j++;
			}
		//}
		return result;
	}
};