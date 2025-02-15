from typing import List

# def add(lst,index,k):
#     for i in range(0,len(lst)):
        
def decrypt( code: List[int], k: int) -> List[int]:
        if k < 0: return decrypt(code[::-1], -k)[::-1]
        n = len(code)
        prefix = code * 2
        for i in range(1, 2 * n):
            prefix[i] += prefix[i - 1]
        for i in range(n):
            code[i] = prefix[i + k] - prefix[i]
        return code            

def decrypt2( code: List[int], k: int) -> List[int]:
    side:List[int]=[0]*(len(code))
    if(k==0): return side
    for i in range(0,len(code)):
        total:int=0
        index=i
        for c in range(0,abs(k)):
            if(k<0):
                index=(index-1)%len(code)
            else:
                index = (index+1)%len(code)
            total+= code[index]
            
        side[i]=total
    return side


# print(7+1+4)
# print(decrypt2(code = [5,7,1,4], k = 3))
# print(decrypt2(code=[2,4,9,3],k=-2))
a=[1,2,3,4]
print(a[::-1])
# print(sum(a[3:1]))