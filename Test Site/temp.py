import random as ran
a="3.1415926535"



def checking(upperLimit:int):
    num:list=[]
    y:int=0
    for i in range(0,upperLimit):
        x=ran.randint(10,100)
        y+=x
        num.append(x)

    num.sort()

    print("average of ",num," is : ",y/10,". Then, passing grade will be : ",y/20," And there are "," \n")

if __name__=="__main__":
    i=0
    while(i<10):
        checking(11)
        i+=1
