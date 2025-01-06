#pragma once
#include<iostream>
#include<stdio.h>
#define Py 24

int  solution(int *arr,int size)
{
    int sol=0;
    for (int i = 0; i < size; i++)
    {
        sol^=arr[i]; 
    }
    return sol;
}