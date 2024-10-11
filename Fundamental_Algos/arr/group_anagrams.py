from collections import defaultdict


def groupAnagrams( strs: list[str]) -> list[list[str]]:
    res=defaultdict(list)

    for string in strs:
        count=[0]*26

        for character in string:
            count[ord(character) -  ord("a")]+=1
        
        res[tuple(count)].append(string)
    
    return res.values()

a=groupAnagrams(["eat","tea","tan","ate","nat","bat"])
print(a)