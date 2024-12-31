#include<fstream>
#include<iostream>
#include<vector>
#include<unordered_map>
typedef std::unordered_map<int,int> map;
typedef std::vector<int> Arr;
std::ostream &operator<<(std::ostream& stream, Arr& vec)
{
    for(int i=0;i<vec.size();i++)
    {
        stream<<vec[i]<<" , ";
    }
    stream<<"\n";
    return stream;
}

void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}


int partition(Arr& arr,int head, int tail)
{
    int index=head;
    int piviot=arr[head];

    for(int h=head+1;h<=tail;h++)
    {
        if(piviot>arr[h])
        {
            ++index;
            swap(arr[h],arr[index]);
        }
    }
    swap(arr[index],arr[head]);
    return index;
}


void quickSort(Arr& arr, int head,int tail)
{
    if(head<tail)
    {
        int partit= partition(arr,head,tail);
        quickSort(arr,head,partit-1);
        quickSort(arr,partit+1,tail);
    }
}


int64_t solve(Arr &left,Arr& right)
{
    quickSort(left,0,left.size()-1);
    quickSort(right,0,right.size()-1);

    int64_t sum=0;
    for(int i=0;i<left.size();i++) sum+= std::abs(left[i]-right[i]);

    return sum;
}

void test(Arr &left,Arr& right)
{
    map x;
    int64_t sol=0;
    for(int i=0;i<left.size();i++)
    {
        for(int y=0;y<right.size();y++)
        {
            if(right[y]==left[i])
            {
                ++x[left[i]];
            }
        }
        sol+= left[i]* x[left[i]];
    }
    std::cout<<sol;
}

int64_t solve2(Arr &left,Arr& right)
{
    quickSort(left,0,left.size()-1);
    quickSort(right,0,right.size()-1);
    int64_t sol=0;

    int prev=left[0];
    int Rit=0,Lit=0;
    while(right[Rit]==prev)
    {
        ++Rit;
    }
    sol+=(prev*Rit);
    for(int i=1;i<left.size();i++)
    {
        if(left[i]==prev)
        {
            sol+=(prev*(Rit-Lit));
        }else{
            prev=left[i];
            Lit=Rit;
            while(right[Rit]==left[i])
            {
                ++Rit;
                std::cout<<"get?\n";
            }
            
            sol+=(left[i]* (Rit-Lit));
        }
    }

    return sol;
}



void input(Arr &left,Arr& right)
{
    std::ifstream inf{"input1.txt"};
    if(!inf)
    {
        std::cout<<"does not exists\n";
    }
    std::string strInput{};
    int x=0;
    while(inf>>strInput)
    {
        if(x&1) right.push_back(std::atoi(strInput.c_str()));
        else left.push_back(std::atoi(strInput.c_str()));
        ++x;
    }
}


int main()
{
    Arr left,right;
    input(left,right);
    quickSort(left,0,left.size()-1);
    quickSort(right,0,right.size()-1);
    // std::cout<<left[0]<<"  "<<right[0];
    // std::cout<<solve2(left,right);
    test(left,right);
}