#AmebaDiv2  If s=X[i], the amoeba should double its size (s=2s)
class AmebaDiv2:
 def simulate(self, X, A):
    for x in X:
        if A == x:
            A *= 2
    return A
