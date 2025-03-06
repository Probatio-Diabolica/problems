#include<iostream>
#include<vector>
#include<algorithm>
void distincts(std::vector<int>& problem)
{
	int sol=1;
	sort(problem.begin(),problem.end());
	for(int i =0;i<problem.size()-1;i++)
	{
		if(problem[i]!=problem[i+1]) ++sol;
	}
	std::cout<< sol<<std::endl;
}


int main()
{
	int el;
	std::cin>>el;
	std::vector<int> pblm(el,0);
	for(int i =0;i<el;i++)
	{
		std::cin>>pblm[i];
	}
	distincts(pblm);
}
