//cpp A--1 B--2 C--3 ....Z--26
int write(string word)
{
    int sum = 0;
    for (char ch: word) {
        sum += ch - 'A' + 1;
    }
    return sum;
}
//Java
public int write(String word) {
    int sum = 0;
    for (int i = 0; i < word.length(); i++) {
        char ch = word.charAt(i);
        sum += ((byte)ch - (byte)'A') + 1; 
    }
    return sum;
}
//python

class WritingWords:
    def write(self, w):
        return sum( (ord(i) - ord('A') + 1) for i in w )
