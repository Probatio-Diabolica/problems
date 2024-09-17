#pragma once
#include <iostream>
class A{
private:
    int width,height;
    int *pixle_arr;
public:
    A(int width,int height):width(width),height(height)
    {
        pixle_arr=new int[width*height];
        for(int i=0;i<width*height;i++){
            pixle_arr[i]=100+i;
        }
    }
    void printARR()
    {
         for(int i=0;i<width*height;i++){
            std::cout<<"<-> "<<pixle_arr[i]<<std::endl;
        }
    } 
};