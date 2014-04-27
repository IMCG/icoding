/*
Each letter of the word is an uppercase English letter.
Equal letters are never consecutive.
There is no subsequence of the form xyxy, where x and y are 
(not necessarily distinct) letters. Note that a subsequence doesn't have 
to be contiguous.
Examples:

Ciel does not like "ABBA" because there are two consecutive 'B's.
Ciel does not like "THETOPCODER" because it contains the subsequence "TETE".
Ciel does not like "ABACADA" because it contains the subsequence "AAAA". (Note that here x=y='A'.)
Ciel likes "A", "ABA", and also "ABCBA".
Given a string word, return "Likes" (quotes for clarity) if Ciel likes word and "Dislikes" if she does not.
*/

/*Something useful: There are 26 upper case letters, this means that there are 
  26*26=676 pairs (X,Y) possible. We can just generate all 676 such pairs. 
  For each of those pairs, we can generate string XYXY. We can check if this 
  string XYXY is a subsequence of the input string. If this is true for any of 
  the generated XYXY strings, then the string is disliked.
 */
// is string a is a subsequence of string b?
bool subSequence(string a, string b)
{
    int i = 0;
    int j = 0;
    while ( (i < b.size()) && (j < a.size() ) ) {
        if (a[j] == b[i]) {
            j ++;
        }
        i ++;
    }
    return (j == a.size() ); 
}
 
string find(string word)
{
    // Any XYXY which is a subsequence?
    for (char X = 'A'; X <= 'Z'; X++) {
        for (char Y = 'A'; Y <= 'Z'; Y++) {
            string xyxy = string(1,X)+string(1,Y)+string(1,X)+string(1,Y);
            if (subSequence(xyxy, word)) {
                return "Dislikes";
            }
        }
    }
    // any two equal consecutive characters?
    for (int i = word.size() - 1; i > 0; i--) {
        if (word[i] == word[i-1]) {
            return "Dislikes";
        }
    }
    return "Likes";
}




