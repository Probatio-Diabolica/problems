#include<vector>
#include<iostream>

std::vector<int> plusOne(std::vector<int>& digits) 
{
    int right=digits.size()-1;
    bool Inc=true;
    while(right!=-1 and Inc)
    {
        if(Inc)
        {
           ++digits[right];
           Inc=false;
           if(digits[right]==10)
           {
                digits[right]=0;
                Inc=true;
                if(right==0) 
                {
                    digits.emplace_back(0);
                    digits[right]=1;
                }

           }

        }
        --right;
    }   
    return digits;     
}

std::ostream& operator<<(std::ostream &stream, std::vector<int> vec)
{
    for(size_t i=0;i<vec.size();i++)
    {
        stream<<vec[i]<<" , ";
    }
    return stream;
}
int main()
{
    std::vector<int> i={9,9,9,9};
    std::cout<<plusOne(i);
}