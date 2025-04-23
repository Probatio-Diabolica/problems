#include "include.hpp"
#include <algorithm>



void star(int sq)
{
	for(int y=0;y<sq;y++)
	{
		for(int x=0;x<sq;x++)
		{
			if((y==x) or ((y+x)==sq-1))std::cout<<'*';
			else std::cout<<" ";
		}
		std::cout<<'\n';
	}
}






void sorttt()
{
	std::vector<float>  vec{10,2.3,-10,0.23};
	std::cout<<vec;
	std::sort(vec.begin(),vec.end());
	std::cout<<vec<<'\n';
}



void matMUL()
{
	std::vector<iArray> arr={{1,2,3},{1,2,3},{1,2,3}},brr = arr,crr=arr;
	std::vector<iArray> res=arr;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			res[i][j]=arr[i][j] * brr[i][j] * crr[i][j];
		}
	}
	std::cout<<res;
}


void pat(int size)
{
	for(int y=0;y<size;y++)
	{
		for(int x=0;x<size;x++)
		{
			if((y==x) or ((y+x)==size-1) or (x==0) or (x==size-1))std::cout<<'*';
			else std::cout<<" ";
		}
		std::cout<<'\n';
	}
}

int main()
{
	sorttt();
	star(5);
	matMUL();
	pat(5);
}
