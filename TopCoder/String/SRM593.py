#http://apps.topcoder.com/wiki/display/tc/SRM+593
class WolfDelaymaster:
 def check(self, s):
     
    # function returns w (r times) o (r times) l (r times) f (r times): 
    def wolf(r):
        return ''.join( ch * r for ch in "wolf" )
         
    if s == '':
        return "VALID"
     
    r = 1
    while 4 * r <= len(s):
        # s[-4*r:] equals the last 4*r characters in the string
        if wolf(r) == s[-4*r:] :
            return self.check( s[ :-4*r] ) #recurse 
            # s[-4*r:] equals the other characters 
        r += 1
         
    # if we didn't find any repeated pattern, it is invalid:
    return "INVALID"