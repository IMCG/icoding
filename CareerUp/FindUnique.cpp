//http://www.careercup.com/question?id=6515637035728896
/*Find first unique number in an unsorted array of 32 bit 
 *numbers without using hash tables or array of counters.
 */

 //eg:1
 int find_unique(int A[],int n){
 	int residx = -1;
 	for (int i = 0; i < n; ++i)
 	{
 		bool uniq = true;
 		for (int j = 0; j < n; ++j)
 		{
 			if(A[i]==A[j] && i!=j){
 				uniq=false;
 				break;
 			}
 		}
 		if(uniq){
 			residx = i;
 			break;
 		}
 	}
 	return residx;
 }
