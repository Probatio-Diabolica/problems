#include<stdio.h>
#define SIZE 10

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
	
}

void thingOne()
{
	int head=0,tail=SIZE;
	int arr[SIZE]={1,2,3,4,5,6,7,8,9,0};
	while(head<SIZE) printf("%d , ",arr[head++]);
	head=0;
	printf("\n");
	while(head<tail) swap(&arr[head++],&arr[--tail]);
	head=0;
	while(head<SIZE) printf("%d , ",arr[head++]);
		
}


int main()
{
	thingOne();
}

