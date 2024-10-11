#include<iostream>
#include<vector>

std::ostream& operator<<(std::ostream &stream,std::vector<int> vec)
{
    stream<<"[" <<vec[0]<<" , "<<vec[1]<<"]\n";
    return stream;
}

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    std::vector<int> sol(2);
    int n=numbers.size();
    for(int left=0;left<n;left++)
    {
        //!! bs
        int head=left+1,tail=n-1,mid=head+ (tail-head)/2;
        while(head<=tail)
        {
            if((numbers[mid]+numbers[left])==target)
            {
                sol[0]=left+1;
                sol[1]=mid+1;
                return sol;
            }
            else if((numbers[mid]+numbers[left])<target) head=mid+1;
            else tail=mid-1;
            mid=head+ (tail-head)/2;
        }
    }
    return sol;
}


int main()
{

    std::vector<int> a={1,2,3,4,5,6,7,8,9};
    std::cout<<twoSum(a,17);
}