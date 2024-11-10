#include<iostream>
#include<vector>
int to_num(std::string a)
{
    int num=0,neg=0,i=0;
    if(a[0]=='-') 
    {
        neg=1;
        i=1;
    }

    for(;i<a.length();i++) num = num * 10 + (a[i] - '0');
    if(neg==1) num*=-1;
    return num;
}
int evalRPN(std::vector<std::string>& tokens) 
{
    int stack[tokens.size()],top=-1;
    for(std::string i : tokens)
    {
        if(i=="+" or i=="*" or i=="/" or i=="-")
        {
            int sy2=stack[top--],sy1=stack[top--];
            switch(i[0])
            {
                case '+':
                    stack[++top]=sy1+sy2;
                    break;
                case '-':
                    stack[++top]=sy1-sy2;
                    break;
                case '/':
                    stack[++top]=sy1/sy2;
                    break;
                default:
                    stack[++top]=sy1*sy2;
                    break;
            }
        }else stack[++top]=to_num(i);
    }
    return stack[top];
}
int main()
{
    std::vector<std::string> token={"4","13","5","/","+"};
    std::cout<<evalRPN(token);
}