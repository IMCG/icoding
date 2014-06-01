#error
str=raw_input().split()
n , m = int(str[0]),int(str[1])
a=raw_input().split()
c=sum(map(int,a))
#n,m,b
print c/m+(c%m>0)


"""
if some group cannot fit all of its members into the current bus, 
it waits for the next bus
"""
#good func
R=lambda:map(int,raw_input().split())
n,m=R()
a=R()

b=0
while a:
    c=m
    while a and c>=a[0]:
        c-=a.pop(0)
    b+=1
print b

