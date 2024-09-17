#include<stdio.h>
int something(){
    int a=8;
    while(a<20){
        printf("help");
        a++;
        if(a==10){
            return a;
        }
    }
    return 0;
}
int main(int argc,char **argv){
   printf("%d",something());
    return 0;
}