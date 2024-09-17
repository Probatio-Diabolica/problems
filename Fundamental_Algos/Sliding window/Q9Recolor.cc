

#include<iostream>


// int min(int a,int b)
// {
//     return a>b ? return a :return b;
// }



int minimumRecolors(std::string blocks, int k) 
{
    // auto min=[](int a,int b)
    // {
    //     return a>b ? a : b;
    // };
    int count=0, paint;
    for(short int i=0;i<k;i++)
    {
        if(blocks[i]=='W') count++;
    }
    paint=count;
    for(short int i=1; i < (blocks.size()-k+1);i++)
    {
        if(blocks[i-1]=='W') count--;
        if(blocks[i+k-1]=='W') count++;
        // paint=min(paint,count);
        paint = paint<count ? paint : count;
    }
    return paint;
}

int main()
{
    
    std::cout<<minimumRecolors("WBBWWBBWBW",7)<<"\n";  
    std::cout<<minimumRecolors("WBWBBBW",2)<<"\n";  
    std::cout<<minimumRecolors("WWBBWBWBWBWBWBBW",4);
}