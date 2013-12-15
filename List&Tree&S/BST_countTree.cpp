int countTree(int numKeys)
{
	if (numKeys <= 1)
		return 1;
	else
	{
		int sum = 0;
		int left, right, root;
		for (root = 1; root <= numKeys; root++)
		{
			left = countTree(root - 1);
			right = countTree(numKeys - root);
			sum += left*right;
		}
		return sum;
	}
}