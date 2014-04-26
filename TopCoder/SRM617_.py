#Python
# this function to check if x is composite is O(x), not O(sqrt(x))
def composite(x):
    return any( x % y == 0 for y in xrange(2,x) )
 
#next()
class SilverbachConjecture:
 def solve(self, n):
    return next( (a,n-a) for a in xrange(4,n) if composite(a) and composite(n-a))
