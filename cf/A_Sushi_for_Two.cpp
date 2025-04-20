#include<iostream>
#include<vector>

#include "include.hpp"

int bs(std::vector<int>& v)
{
	int sol = 2;
	int eel=0, tuna = 0; // tuna represented by 1, eel being done by 2  
	int __temp = v[0];
	int prev = v[0];

	for(int i = 0 ; i<v.size();i++)
	{
		if(v[i]!=prev) 
		{
			
			if( (2*std::min(eel , tuna)) > sol ) sol = 2*std::min(eel , tuna); 
			prev = v[i];
			//tuna-eel config!!
			// simply change the prev to the old valu
			//e 
			if(__temp == 1) 
			{
			       	__temp = 2;
				tuna = 0;
			}else 
			{ 
				__temp = 1;
				eel = 0;
			}
			
		}
		//core
		(v[i] == 1) ? ++tuna : ++eel;
	}
 	return sol;
}

int main()
{
	int n;
	std::cin>>n;
	std::vector<int> v(n);
	for(int i = 0 ;i<n;i++)
	{
		std::cin>>v[i];
	}
		
	std::cout<<bs(v);
}
