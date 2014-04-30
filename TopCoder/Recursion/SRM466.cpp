//subset 好方法。二进制表示
string buy(int price, int b1, int b2, int b3, int b4)
    {
        int b[4] = {b1, b2, b3, b4};
        // We will generate the subset from bits of i
        // Iterate over all i from 0 to 2^n-1
        for (int i = 0; i < 16; i++)
        {
            int sum = 0;
            for (int j = 0; j < 4; j++)
                if (i & (1<<j)) // Check whether or not to include the j-th element
                    sum += b[j]; // Get sum of all included elements
            if (sum == price) return "POSSIBLE";
        }
        return "IMPOSSIBLE";
    }