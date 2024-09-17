def countGoodSubstrings(s)->int:
    gs:int=0
    for i in range(1,len(s)-1):
        if((s[i]!=s[i-1]) and (s[i]!=s[i+1])and (s[i-1]!=s[i+1])):gs+=1
        
    return gs



print(countGoodSubstrings("dhfksjhfksdhkdskjbcnzxmiodiezxc"))