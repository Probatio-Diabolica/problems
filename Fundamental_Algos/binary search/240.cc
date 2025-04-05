#include"includes.hpp"

using left = int;
using right = int;

std::pair<left,right> BS()
{
    std::pair<int,int> p={0,0};
    return p;
}


std::pair<left,right> interval1(vector<vector<int>>& matrix, int target)
{
    std::pair<left,right> p{-1,-1};
    int head = 0,tail = matrix.size();
    while(head<=tail)
    {
        int mid = head +(tail - head) /2;
        int begin = matrix[mid][0],end = matrix[mid][matrix[mid].size()-1];
        if(target > begin and target < end) head=mid +1;
        else 
        {
            if(target > begin) head = mid + 1;
            else if(target < begin) tail = mid -1;
            else if()
        }
    }
    return p;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int head = 0, tail=matrix.size();
    std::pair<left,right> p = interval1(matrix,target);
    head= p.first, tail= p.second; 


}

int main()
{
    iMat x{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};    
    std::cout<<searchMatrix(x, 16);

}