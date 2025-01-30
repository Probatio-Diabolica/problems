#include<iostream>
#include<vector>
#include<stack>
std::ostream& operator<<(std::ostream& stream , std::vector<int> vec)
{
    for(int i : vec) stream<<i<<" ,";
    return stream;
}


std::vector<int> dailyTemperatures(std::vector<int>& temps) {
    int n=temps.size();
    std::vector<int> results(n);
    std::stack<int> stack;
    for (int i = 0; i < n; i++) 
    {
        while (!stack.empty() && temps[stack.top()] < temps[i]) 
        {
            results[stack.top()] = i - stack.top();
            stack.pop();
        }
        stack.push(i);
    }

    return results;
}

int main()
{
    std::vector<int> a={30,60,90};
    std::cout<<dailyTemperatures(a)<<"\n";
}