class EllysSubstringSorter:
 def getMin(self, S, L):
     
    # generate device output for i
    def device(i):
        return S[0:i] + ( ''.join( sorted(S[i:i+L]) ) ) + S[i+L:]
      
    # pick minimum (lexicographically-first) possible output:
    return min( device(i) for i in range( len(S) - L + 1) )