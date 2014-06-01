a,k=map(int,raw_input().split())
#k times
a=list(str(a))
#b=""
while k:
    for i in range(len(a)-1):
        if a[i]<a[i+1]:
            a[i],a[i+1]=a[i+1],a[i]
            break
    k-=1

print int(''.join(a))

#选择最远最大的,当k=0时直接加到了b上
a,k=map(int,raw_input().split())
a=list(str(a))
b=''

while a:
    pos=a.index(max(a[:k+1]))
    b+=a[pos]
    k-=pos
    a.pop(pos)
    if k==0:
        b+=''.join(a)
        break;
print b