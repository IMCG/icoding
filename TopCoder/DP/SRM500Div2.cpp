// SRMCards
//既然想到了顺序遍历，就不用删除节点了
class SRMCards{
public:
	int maxTurns(vector <int> c)
	{
		int ran = c.size();
		int count = 0;
		int k;
		sort(c.begin(), c.end());
		for (k = 0; k<ran; k++)
		{
			if ((c[k] + 1) == c[k + 1]) k++;
			count++;
		}

		return count;
	}
};