#include"include.hpp"
#include<random>

typedef unordered_map<int,int> iMap;


void swap(int& a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}


class RandomizedSet {
public:

public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(m_mp[val]>0)
        {
            return false;
        }
        m_arr[++m_top]=val;
        m_mp[val]=m_top+1;        
        return true;
    }
    
    bool remove(int val) {
        if(m_mp[val]>0)
        {
            swap( m_arr[m_mp[val]-1] , m_arr[m_top] );
            m_mp[val]=0;
            --m_top;
            return true;
        }
        return false;
    }
    
    int getRandom() {

        return m_arr[rand()%(m_top+1)];
    }

private:
    iMap m_mp;
    int m_arr[9500];
    int m_top=-1;
};

int main()
{
    RandomizedSet r = RandomizedSet();
    cout<<"\n"<<r.insert(2);
    cout<<"\n random :: "<<r.getRandom();
    for(int i=0;i<10;i++)
    {
        cout<<"\n"<<r.insert(i);
    }
    
    cout<<"\n"<<r.remove(2);
    cout<<"\n"<<r.insert(2);
    cout<<"\n random :: "<<r.getRandom();
    cout<<"\n"<<r.remove(1);
    cout<<"\n"<<r.insert(2);
    for(int i=0;i<10;i++)
    {
        cout<<"\n random :: "<<r.getRandom();
    }

}
