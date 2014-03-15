bool next_permutation(vector<int> &arr) {
	//自己实现的话最好assert(arr.size());
    return next_permutation(arr.begin(), arr.end());
}
//自己实现
template<typename BidiIt>
bool next_p(BidiIt first, BidiIt last)
{
	auto rfirst = reverse_iterator<BidiIt>(last);
	auto rlast = reverse_iterator<BidiIt>(first);

	auto pivot = next(rfirst);
	while (pivot != rlast && !(*pivot < *prev(pivot)))
		pivot++;

	if (pivot == rlast){
		reverse(rfirst, rlast);
		return false;
	}
	auto change = find_if(rfirst, pivot, bind1st(less<int>(),*pivot));
	swap(*pivot, *change);
	reverse(rfirst, pivot);
	return true;
}