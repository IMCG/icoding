//删除重复元素。
template<typename InIt,typename OutIt>
OutIt removeDuplicates(InIt first, InIt last,
	OutIt output){
	while (first != last){
		*output++ = *first;
		first = find_if(first, last,
			bind1st(not_equal_to<int>(), *first));
	}
	return output;
}
//双向迭代器  全排列
template<typename BidiIt>
bool next_permuta(BidiIt first, BidiIt last)
{
	const auto rfirst = reverse_iterator<BidiIt>(last);
	const auto rlast = reverse_iterator<BidiIt>(first);

	auto pivot = next(rfirst);
	while (pivot != rlast && !(*pivot < *prev(pivot)))
		++pivot;
	if (pivot == rlast){
		reverse(rfirst, rlast);
		return false;
	}
	auto change = find_if(rfirst, pivot,
		bind1st(less<int>(), *pivot));
	//iter_swap(change, pivot);
	swap(*pivot, *change);
	reverse(rfirst, pivot);
	return true;
}