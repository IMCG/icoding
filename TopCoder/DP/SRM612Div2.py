def f(s):
	return 0 if s == 1 else min(f(x) + s/x for x in divisors(s))
def divisors(s):
	return (x for x in xrange(1,s) if s % x ==0) #prper divisors of s

class EmotionsDiv2:
	printSmiles = staticmethod(f)
	