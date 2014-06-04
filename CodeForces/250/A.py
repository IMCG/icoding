#好好理解
choices = [(x, raw_input()[2:]) for x in ['A', 'B', 'C', 'D']]
valid = [x for x, s in choices if all(len(s) >= 2 * len(o) for y, o in choices if x != y) or 
                                  all(2 * len(s) <= len(o) for y, o in choices if x != y)]



a=[]
for i in range(4): a.append(raw_input()[2:])
g=[i for i in range(4) if (all((len(a[i])*2<=len(a[j]) or j==i) for j in range(4)) or 
						  all((len(a[i])>=len(a[j])*2 or j==i) for j in range(4)))]
