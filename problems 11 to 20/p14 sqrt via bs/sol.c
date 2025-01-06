#include<stdio.h>
int mySqrt(int x) {
    int head=0;
    int tail=x;
    long long int mid=x/2;
    int ans;
    while(head<=tail){
        if(mid*mid > x){
            tail=mid-1;            
        }else if(mid*mid < x  ){
            head=mid+1;
            ans=mid;
        }else{
            return mid;
        }
        mid=head+ (tail-head)/2;
    }
    return ans;    
}
int main(int argc, char **argv){
    
    printf("%d",mySqrt(2147395599));
    return 0;
}