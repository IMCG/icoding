class DivideByZero:
	def CountNumbers(self,numbers):
		s = set(numbers)
		old = 0
		#repeat as long as there are new numbers in the list:
		while len(s) > old:
			old = len(s)
			# find a good pair (a,b) 
			for a in list(s):
				for b in list(s):
					if a > b and a/b not in s:
						s.add(a/b)
	return len(s)