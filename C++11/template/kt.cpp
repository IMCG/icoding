//康托展开。
class Solution {
public:
	string getPermutation(int n, int k) {
		string s(n, '0');
		for (int i = 0; i < n; i++)
			s[i] += i + 1;

		return kth_permutation(s, k);
	}
private:
	int factorial(int n){
		int result = 1;
		for (int i = 1; i <= n; i++)
			result *= i;
		return result;
	}
	// seq 已排好序，是第一个排列
	template<typename Sequence>
	Sequence kth_permutation(const Sequence &seq, int k) {
		const int n = seq.size();
		Sequence S(seq);
		Sequence result;
		int base = factorial(n - 1);
		--k; // 康托编码从0 开始
		for (int i = n - 1; i > 0; k %= base, base /= i, --i) {
			auto pos = next(S.begin(), k / base);
			result.push_back(*pos);
			S.erase(pos);
		}
		result.push_back(S[0]); // 最后一个
		return result;
	}
};