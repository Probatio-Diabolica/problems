#include<iostream>
#include <math.h>

std::string integer_to_string(int value)
{
    if (value == 0) return "0";
    
    bool negative = value < 0;
    value = std::abs(value);
    
    char buffer[12];  // Enough for 32-bit int plus sign
    char* p = buffer + sizeof(buffer);
    
    while (value > 0) {
        *--p = '0' + value % 10;
        value /= 10;
    }
    
    if (negative) *--p = '-';
    
    return std::string(p,buffer+sizeof(buffer)-p); 
    //$ p <- this points at the first element of 'value' as a string in the buffer
    //$ buffer + sizeof(buffer) -p == lenght of buffer minus the first element of 'value' inside buffer
    //// for example, if 'value' = 129, then it will look like this [n-n-n-n-n-n-n-n-n-1-2-9], 
    //!! now we will return only the used spaces as a string
}


int divisorSubstrings(int num, int k) 
{
    std::string snum=integer_to_string(num);
    int sum=0;
    for(int i=0;i<k;i++)
    {
        
    }
    return sum     ;   
}


int main()
{
    std::cout<<divisorSubstrings(240,2)<<"\n";
    // std::cout<<divisorSubstrings(43006,2)<<"\n";
    // std::cout<<divisorSubstrings(236728,3)<<"\n";
    // std::cout<<divisorSubstrings(76357,4)<<"\n";
    // std::cout<<divisorSubstrings(212,1)<<"\n";
}
