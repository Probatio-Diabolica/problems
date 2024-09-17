
class ans:
    def swap(self,arr:list,ina,inb):
        temp=arr[ina]
        arr[ina]=arr[inb]
        arr[inb]=temp
    def doShift(self,arr,arr2):
        count=len(arr)
        adday:list=arr
        for i in arr2:
            adday.append(i)
            count+=1
        adday.sort()
        
        for i in range(1,len(adday)):
            if(adday[i]==adday[i-1]):
                count-=1
        return count




if __name__=="__main__":
    anna=ans()
    a=[1,1,6]
    b=[1,5,6]
    print(anna.doShift(a,b))