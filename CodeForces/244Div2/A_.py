#A Police Recruits
input()
s = n = 0
for i in map(int,input().split()):
	s += i
	if(s < 0):
		s = 0
		n += 1
print(n)
#B Prison Transfer
