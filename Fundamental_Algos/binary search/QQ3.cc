#include<iostream>
#include<vector>

bool search(std::vector<int>& vec,int target)
{
    int head=0,tail=vec.size()-1,mid=head+(tail-head)/2;
    while(head<=tail)
    {
        if(target==vec[mid]) return true;
        else if(target<vec[mid]) tail=mid-1;
        else head=mid+1;
        mid=head+(tail-head)/2;
    }
    return false;
}

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) 
{
    int rowSize=matrix.size();
    for(int row=0;row<rowSize ;row++) if(target>=matrix[row][0] and target<=matrix[row][matrix[row].size()-1]) return search(matrix[row],target);
    return false;
}
int main()
{
    std::vector<std::vector<int>> a={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    std::cout<<searchMatrix(a,610);
}