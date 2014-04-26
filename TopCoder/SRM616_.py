#we can use itertools.cycle 
import itertools
class WakingUpEasy:
    def countAlarms(self,volume,S):
        i=0
        for a in itertools.cycle(volume):
            i+=1
            S-=a
            if S<=0:
                break;
        return i



