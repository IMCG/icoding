
//WiKi
//我们可以穷举所有的区间，看是否符合要求
int getCount(vector <int> luckySet, int n)
{
	int r = 0;
	int C = *max_element(luckySet.begin(), luckySet.end());
	for (int A = 1; A <= C; A++)
		for (int B = A + 1; B <= C; B++)
		{
			bool good = true;
			for (int i = 0; i<luckySet.size(); i++)
				if ((B >= luckySet[i]) && (luckySet[i] >= A))
					good = false;

			if (good && (B >= n) && (n >= A))
				r++;
		}
	return r;
}
/*Find two consecutive elements luckySet[i] and luckySet[i+1] such that 
(luckySet[i] < n) and (luckySet[i]>n).
There are (n - luckySet[i]) different values for A and (luckySet[i+1] - n) 
different possible values for B. The total number of unlucky intervals 
becomes : (n - luckySet[i])*(luckySet[i+1] - n), since according to the 
statement, B>A, we subtract 1 from this result.
*/
int getCount(vector<int> v, int X){
	v.push_back(0);
	sort(v.begin(), v.end());
	//index...
	int idx = distance(v.begin(), lower_bound(v.begin(), v.end(), X));
	if (v[idx] == X) return 0;
	//数学的方法
	return  (n - v[idx - 1] - 1)*(v[idx] - n) + (v[idx] - n - 1);
}