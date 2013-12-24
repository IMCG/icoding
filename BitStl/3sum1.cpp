// Dedup directly, 
// LeetCode Judge Large, 272 milli secs.
vector<vector<int> > three_sum(vector<int> &num) 
{
    vector<vector<int> > ret;
    
    if (num.size() == 0) return ret;
    
    sort(num.begin(), num.end());
    
    for (vector<int>::const_iterator it = num.begin();
        it != num.end();
        ++it)
    {
        // Dedup
        if (it != num.begin() && *it == *(it - 1))
        {
            continue;
        }
        
        // Dedup, front = it + 1
        vector<int>::const_iterator front = it + 1;
        vector<int>::const_iterator back = num.end() - 1;
        
        while (front < back)
        {
            const int sum = *it + *front + *back;
            
            if (sum > 0)
            {
                --back;
            }
            else if (sum < 0)
            {
                ++front;
            }
            // Dedup
            else if (front != it + 1 && *front == *(front - 1))
            {
                ++front;
            }
            // Dedup
            else if (back != num.end() - 1 && *back == *(back + 1))
            {
                --back;
            }
            else
            {
                vector<int> result;
                
                // Already sorted.
                result.push_back(*it);
                result.push_back(*front);
                result.push_back(*back);
                
                ret.push_back(result);
                
                ++front;
                --back;
            }
        }
    }
    
    return ret;
}