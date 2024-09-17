def onion(numsA:list,numsB:list):
    ans:list=set(numsA+numsB)
    print(ans)
    return len(ans)
if __name__ == "__main__":
    a=[1,2,3,4,5,6,77777]
    b=[2,3,4,5,6,8]
    print(onion(a,b))