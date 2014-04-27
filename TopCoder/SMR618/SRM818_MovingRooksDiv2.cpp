//转换为图的知识
string move(vector<int> Y1, vector<int> Y2)
{
    // A set to mark the already-visited places:
    set<vector<int>> visited = {Y1}; //We start at Y1.
    queue<vector<int>> Q; 
    Q.push(Y1);
     
    // while queue is not empty:
    while ( ! Q.empty() ) {
        auto x = Q.front(); Q.pop(); //fetch the front of the queue in x.
        // generate the possible moves from x to some permutation
        for (int i = 0; i < x.size(); i++) {
            for (int j = i + 1; j < x.size(); j++) {
                // we have i < j and x[i] > x[j]:
                if (x[i] > x[j]) {
                    swap(x[i],x[j]);               //swap
                    if ( visited.count(x) == 0 ) { // If we didn't visit it:
                        visited.insert(x);         // Mark as visited
                        Q.push(x);                 // push to queue
                    }
                    swap(x[i],x[j]);               //restore
                }
            }
        }
         
    }
    // If Y2 is reachable from Y1, return Possible
    return visited.count(Y2) ? "Possible" : "Impossible";
}
