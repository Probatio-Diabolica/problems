def amt(lis,lim):
    if(lim==0): return lis[0]
    return lis[lim]+ amt(lis,lim-1)

def shiftDistance( s: str, t: str, nextCost, previousCost) -> int:
        N=len(s)
        diff=0
        cost=0
        for i in range(0,N):
            if(s[i]=='z'):
                s[i]='a'
                cost+=amt(nextCost,25)
            elif(s[i]=='a') : 
                s[i]='z'
                cost += amt[previousCost,0]
            
            if(ord(s[i]) > ord(t[i])):
                diff=ord(s[i]) - ord(t[i])
                if(diff>13) : 
                    diff=13 - (diff%13)
                    cost+= previousCost[diff]*diff
                else:
                    cost+= nextCost[diff]*diff
                    
            elif(ord(s[i]) < ord(t[i])) : 
                diff=ord(t[i]) - ord(s[i])
                if(diff>13) : 
                    diff=13 - (diff%13)
                    cost+= previousCost[diff]*diff
                else:
                    cost+= nextCost[diff]*diff
        
        return cost

print(shiftDistance("abab","baba",nextCost=[100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],previousCost=[1,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]))
print(shiftDistance(s="leet",t="code",nextCost=[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1],previousCost=[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]))