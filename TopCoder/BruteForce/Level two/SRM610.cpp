//SRM610 Div2-500 不会 GOOD
//http://apps.topcoder.com/wiki/display/tc/SRM+610

/*The rectangle we have to search for can be described by two corners: 
(x0,y0), (x1,y1), what we can do is fix the start and final columns, 
the x0=i and x1=j coordinates. Then we are interested in finding the maximum 
height of a correct subrectangle inside the matrix composed of columns between 
x0=i and x1=j, inclusive. For each pair (i,j), we can ignore the other columns.

Each of the sub-rows should be of the kind 010101... or 1010101... with an 
O(n2) we can find whether each of these sub-rows belongs to either of those types. 
We can flag them as type '0' for 010101... , type '1' for 10101010... and we 
should also flag 'x' to the rows that don't belong to any of those types.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//O(n^4)
class TheMatrix{
public:
	int MaxArea(vector<string> board)
	{
	    int res = 0, w = board[0].size(), h = board.size();
	    // fix columns i and j:
	    for (int i = 0; i < w; i++) {
	        for (int j = i; j < w; j++) {
	            // the flags for each row:
	            char row[h];
	             
	            // find the flags, 0 for rows 010101.., 1 for rows 101010... X for other.
	            for (int k = 0; k < h; k++) {
	                bool alt = true;
	                for (int r = i + 1; r <= j; r++) {
	                    alt = alt && (board[k][r] != board[k][r-1]);
	                }
	                row[k] = ( alt ? board[k][i] : 'X' );
	            }
	             
	            // Find the largest substring of alternating 0s and 1s:
	            int mh = 0, ch = 0;
	            for (int k = 0; k < h; k++) {
	                if ( row[k] == 'X' ) {
	                    ch = 0;
	                } else if ( (ch > 0) && (row[k-1] != row[k]) ) {
	                    ch++;
	                } else {
	                    ch = 1;
	                }
	                mh = max(mh, ch);
	            }
	            // The largest height is mh, the width is j - i +1
	            res = std::max(res, mh * (j - i + 1) );
	        }
	    }
	    return res;
	}
};
//O(n^3)
/*For each row k, if the flag for j−1 was "X", the flag will also be "X", else if the
 bit at position (k,j) is different to the bit at position (k,j−1) the flag can 
 stay the same (the first character of the sequence is the one at column i).
*/
 int MaxArea(vector<string> board)
{
    int res = 0, w = board[0].size(), h = board.size();
    // fix columns i and j:
    for (int i = 0; i < w; i++) {
        // the flags for each row:
        char row[h];
        for (int j = i; j < w; j++) {
             
            if (j == i) { //initialize flags:
                for (int k = 0; k < h; k++) {
                    row[k] = board[k][i];
                }
            } else {
                // update the flags, 0 for rows 010101.., 1 for rows 101010... X for other.
                for (int k = 0; k < h; k++) {
                    if (board[k][j] == board[k][j-1] ) {
                        row[k] = 'X';
                    }
                }
            }
             
            // Find the largest substring of alternating 0s and 1s:
            int mh = 0, ch = 0;
            for (int k = 0; k < h; k++) {
                if ( row[k] == 'X' ) {
                    ch = 0;
                } else if ( (ch > 0) && (row[k-1] != row[k]) ) {
                    ch++;
                } else {
                    ch = 1;
                }
                mh = max(mh, ch);
            }
            // The largest height is mh, the width is j - i +1
            res = std::max(res, mh * (j - i + 1) );
        }
    }
    return res;
}