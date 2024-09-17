#include<iostream>
#include<vector>

std::ostream& operator<<(std::ostream &stream, std::vector<int> &vec)
{
    for(size_t i=0;i<vec.size();i++)
    {
        stream<<vec[i]<<" , ";
    }
    return stream;
}
int removeDuplicates(std::vector<int>& nums) 
{
    if (nums.empty()) return 0;

    int unique = 1;
        auto it = nums.begin() + 1;

    while (it != nums.end()) 
    {
        if (*it != *(it - 1)) {
            ++unique;
            ++it;
        } else {
            it = nums.erase(it);
        }
    }

        return unique; 
}
int main()
{
    std::vector<int> a={0,2,3,4,4,4,5,8};
    std::cout<<removeDuplicates(a);
}