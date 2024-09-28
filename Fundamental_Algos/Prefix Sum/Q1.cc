#include<iostream>
#include<vector>
std::ostream& operator<<(std::ostream& stream,std::vector<int> vec)
{
	for(int i: vec) stream <<i <<" , ";
	return stream;
}


class NumArray {
private:
	std::vector<int> m_sumArr;
public:

    NumArray(std::vector<int>& nums) 
    {
	int sum =0;
	for(int i=0;i<nums.size();i++)
	{
		sum+=nums[i];
		m_sumArr.push_back(sum);
	}
	std::cout<<m_sumArr<<"\n";
    }

    int sumRange(int left, int right) 
    {
	return (left==0)? m_sumArr[right]:m_sumArr[right] - m_sumArr[left-1];
    }
};

int main()
{
	std::vector<int> a={-2, 0, 3, -5, 2, -1};
	NumArray* sol=new NumArray(a);
	std::cout<<sol->sumRange(0,2)<<"	||	"<<sol->sumRange(2,5)<<"	||	"<<sol->sumRange(0,5)<<"\n";
	delete sol;

}






