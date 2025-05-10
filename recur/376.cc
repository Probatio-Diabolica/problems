#include<iostream>
#include <ostream>
#include<vector>
using namespace std;

// int subsequence(vector<int>& diffArray,int idx,int currElement)
// {
//     return 0;
// }

static int wiggleMaxLength(vector<int>& nums) 
{

    // return subsequence(nums,0);
    return nums[0];
}

static std::ostream& operator<<(std::ostream& stream, vector<int>& vec)
{
    for(int const i: vec) { stream<<i<<' ';
}
    return stream;
}
int main()
{
    vector<int> v{1,7,4,9,2,5};

    cout<<v;
}