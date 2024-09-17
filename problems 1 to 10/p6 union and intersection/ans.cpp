#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int doUnion(int arr[], int arr2[], int size,int size2){
    int count=size+size2;
    int adday[count];
    for(int i=0;i<size;i++) adday[i]=arr[i];
    for(int i=0;i<size2;i++) adday[i+size] = arr2[i];
    sort(adday, adday + count);
    for(int i=1;i<size+size2;i++) 
    {
        if(adday[i]==adday[i-1]) count--;
    }
    return count;


}

int main(){
    int arr[]={6,8,0};
    int arr2[]={1,2,3,4,5,6,7};
    // int sizA=3;
    // int sizB=7;
    cout<<doUnion(arr,arr2,3,7);
    return 0;
}