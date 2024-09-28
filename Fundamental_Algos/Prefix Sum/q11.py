class MyCalendarTwo:
    def __init__(self):
        self.non_overlapping=[]
        self.overlapping=[]        

    def book(self, start: int, end: int) -> bool:
        for s,e in  self.overlapping:
            if end>s and e>start:
                return False
        
        for s,e in self.non_overlapping:
            if end > s and e>start:
                self.overlapping.append(
            (max(s,start),min(e,end))
        )
        self.non_overlapping.append((start,end))
        return True
        
    
if __name__ == "__main__":
    cal= MyCalendarTwo()
    print(cal.book(28,46)) #true
    print(cal.book(9,21))
    print(cal.book(21,39))
    print(cal.book(37,48))
    print(cal.book(38,50))
    print(cal.book(22,39)) 
    print(cal.book(45,50)) #true
    print(cal.book(1,12))
    print(cal.book(40,50))
    print(cal.book(31,44))
    