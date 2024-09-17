#include<stdio.h>
void condition(){
    int i=0;
    while (i<10)
    {
            if(i%2==0 && i<8){
                printf("\neven : %d\n", i);
            }else if(i>2){
                printf("\nbigger than 2; %d\n", i);
            }
            
            if(i>3) printf("\n gjhsgdj %d\n",i);
    i++;
    printf("---------------------------------------------\n");
    }
    
}

void loop(){
    for(int i=0;i<10;i++)
        printf("%d\n",i);
}
int main(){
    //condition();
    //loop();
    printf("%d", 71%4);
    return 0;
}