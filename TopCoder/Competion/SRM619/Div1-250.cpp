//偶数剪枝
class SplitStoneGame {
public:
	string winOrLose(vector <int> number) {
		int n = number.size();
		int val = *max_element(number.begin(), number.end());
		if (val <= 1 || n <= 2) return "LOSE";
		else if (n % 2 == 0) return "LOSE";
		else return "WIN";
	}
};
