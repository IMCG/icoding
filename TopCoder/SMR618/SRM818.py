import string
 
class LongWordsDiv2:
 def find(self, word):
    def isSubsequence(a, b):
        i = 0
        j = 0
        while i < len(b) and j < len(a):
            if a[j] == b[i]:
                j += 1
            i += 1
        return j == len(a) 
      
    for i in range(len(word)-1):
        if word[i] == word[i+1]:
            return "Dislikes"
             
    for X in string.uppercase:
        for Y in string.uppercase:
            if isSubsequence(X+Y+X+Y, word):
                return "Dislikes"
