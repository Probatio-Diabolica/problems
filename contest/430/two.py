def answerString(word: str, numFriends: int) -> str:
        if numFriends == 1:
            return word
        
        n = len(word)
        maxLen = n - numFriends + 1
        best = ""
    
        for i in range(n):
            q = word[i:i+maxLen]
            best = max(best, q)
    
        return best

print(max("psdf","poiu"))
print(answerString("sdfghyujkl",5))