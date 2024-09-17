#include<iostream>
/*void swap(int* a, int* b){
    *a = *b+*a;
    *b=*a - *b;
    *a=*a -*b;
}*/

void swap(int* a, int* b){
    *a = *b+*a;
    *b=*a - *b;
    *a=*a -*b;
}
void swap2(int& a, int& b){
    int temp=a;
    a=b;
    b=temp;
}
// int main(){
//     int a= 10;
//     int b=3;
//     swap(&a,&b);
//     printf("%d",a);
// }
void funky(){}
int main(){
    int a=10,b=90;
    swap(&a,&b);
    std::cout<< "a = " <<a <<" b = "<< b;
    return 0;
}