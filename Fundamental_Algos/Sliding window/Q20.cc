#include"includes.hpp"

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) 
{
        std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    if (nums.empty() || k <= 0 || k > static_cast<int>(nums.size())) {
        return {};
    }
    std::vector<int> result;
    result.reserve(nums.size() - k + 1);
    std::deque<size_t> dq;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (!dq.empty() && dq.front() + k <= i) {
            dq.pop_front();
        }
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}

// std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) 
// {
//     std::vector<int> sol={};
//     std::pair<int,int> max={nums[0],0},subMax={INT_MIN,0};
//     for(int i=0;i<k and k<nums.size();i++)
//     {
//         if(nums[i]>max.first) max={nums[i],i};
//         if(nums[i]>subMax.first && max.first>nums[i]&& max.second<i) subMax={nums[i],i};
//     }
//     sol.push_back(max.first);
//     for(size_t winPoint=1;winPoint<nums.size()-k+1;winPoint++)
//     {   
//         std::pair<int,int> el={nums[winPoint+k-1],winPoint+k-1};
//         if(max.second==(winPoint-1))// deletion
//         {
//             max=subMax;
//             subMax=el;
//         }
//         if(max.first<el.first)// insertion
//         {
//             max=el;
//             subMax={nums[winPoint-k+1],winPoint-k+1};
//         }
//         else if(subMax.first<el.first) subMax=el;
//         sol.push_back(max.first);
//     }      
//     return sol;  
// }
std::ostream& operator<<(std::ostream& stream,std::vector<int> vec)
{
    for(auto i:vec) stream<<i<<" ";
    return stream;
}
int main()
{
    std::pair<std::vector<int>,int> a={{1,3,-1,-3,5,3,6,7},3};
    std::pair<std::vector<int>,int> b={{3,6,2,3,4},2};
    std::pair<std::vector<int>,int> c={{9,10,9,-7,-4,-8,2,-6},5};
    std::pair<std::vector<int>,int> d={{-6,-10,-7,-1,-9,9,-8,-4,10,-5,2,9,0,-7,7,4,-2,-10,8,7},7};
    std::cout<<maxSlidingWindow(a.first,a.second)<<"\n";
    std::cout<<maxSlidingWindow(b.first,b.second)<<"\n";
    std::cout<<maxSlidingWindow(c.first,c.second)<<"\n";
    std::cout<<maxSlidingWindow(d.first,d.second);
}