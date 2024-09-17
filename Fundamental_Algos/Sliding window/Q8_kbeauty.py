def divisorSubstrings( num: int, k: int) -> int:
    snum:str=str(num)
    kBeauty:int=0
    sum=int(snum[:k])
    if sum!=0:
        if num%sum==0 : kBeauty+=1
    for i in range(1,len(snum)-(k-1)):
        sum-=int(snum[i-1])* (10**(k-1))
        sum*=10
        sum+=int(snum[i+k-1])
        if sum!=0:
            if num%sum==0: kBeauty+=1
        
    return kBeauty

def divisorSubstrings2( num: int, k: int) -> int:
    snum=str(num)
    b=0
    for i in range (len(snum)- k+1):
        x=int(snum[i:i+k])
        if(x!=0 and num%x==0): b+=1
    return(b)
# s = str(num)
# b = 0

# for i in range(len(s) - k + 1):
#         x = int(s[i : i + k])
#         if( x!= 0 and num%x==0):
#             b+=1
# return(b)


print(divisorSubstrings2(240,2))
print(divisorSubstrings(240,2))
print(divisorSubstrings2(430043,2))

print(10**2)