# return the array by sawaping the alternative elements

# input
>arr = [1,2,3,4,5] 
# output   
>arr = [2,1,4,3,5] 

# solution
swap(element& a,element& b)
{
    element temp=a;
    a=b;
    b=temp;
}

prob(vec<int> &num)
{
    int head=0,tail=num.size()-1;
    while (head <= tail-2)
    {
        swap(num[head],num[head+1]);
        head+=2;
    }
}