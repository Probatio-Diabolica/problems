#include<stdio.h>


void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[], int head, int tail){
    int index=head;
    int pivot=arr[head];
    for(int i=head+1;i<=tail;i++){
        if(pivot>arr[i]){
            index++;
            swap(&arr[index],&arr[i]);
        }
    }
    swap(&arr[head],&arr[index]);
    return index;
}
void Qsort(int arr[],int head,int tail){
    if(head<tail){
        int index=partition(arr,head,tail);
        Qsort(arr,head,index-1);
        Qsort(arr,index+1,tail);
    }
}
int doUnion(int a[], int n, int b[], int m){
    int size=n+m;
    int adday[size];
    int j=0;
    for(int i=0;i<n;i++) adday[i]=a[i];
    for(int i=n;i<n+m;i++)
    {
        adday[i]=b[j++];//j++ right noe means increment j after this statement but not now
    }
    Qsort(adday,0,size);
    int count=0;
    for (int i = 0; i < size; i++)
    {
        if(adday[i]!=adday[i+1]){
            count++;
        }
    }
    return count;

}
int main(){
    int arr[]={-12 , -13 , -5 , -7 , -3 , -6 , 5 , 6 , 11 };
    int arr2[]={-13, 389, 914};
    printf("%d ",doUnion(arr,9,arr2,3));
    return 0;
}