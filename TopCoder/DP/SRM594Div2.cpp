// AstronomicalRecordsEasy
//set 的运用
int minimalPlanets(vector<int> A, vector<int> B)
{
    int res = A.size() + B.size();
    for (int p: A) {         // For each p = A[i]
        for (int q: B) {        // For each q = B[i]
            // Count the number of unique elements in the A and B:
            set<int> seen;
            for (int x: A) {
                seen.insert( x * q );
            }
            for (int x: B) {
                seen.insert( x * p );
            }
            // (We add elements to a set because they are added at most once)
            res = std::min<int>(res, seen.size() );
        }
    }
    return res;
}