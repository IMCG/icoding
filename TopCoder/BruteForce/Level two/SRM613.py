##我只考虑了0 的情况
class TaroFriends:
 def getNumber(self, X, T):
    # move cat at position z towards x
    def towards(z,x):
        return z + T if z <= x else z - T
     
    # calculate the distance if all cats move towards x
    def allTowards(x):
        l = [ towards(z, x) for z in X ]
        return max(l) - min(l)
         
    # pick the minimum distance if all cats move towards point x
    return min( allTowards(x) for x in X)