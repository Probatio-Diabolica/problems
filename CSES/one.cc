#include<iostream>

void simulate(long long n)
{
	while(n!=1)
	{
		std::cout<<n<<" ";
		if(n&1) n=(n*3) +1;
		else n/=2;
	}
	std::cout<<n<<std::endl;
}

int main()
{
	long long n;
	std::cin>>n;
	simulate(n);
}
