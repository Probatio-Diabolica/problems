#include"includes.hpp"
using minHeap = std::priority_queue<int,std::vector<int>,std::greater<int>>;
using maxHeap = std::priority_queue<int>;
class MedianFinder {
    public:
        MedianFinder() 
        {
            
        }
        
        void addNum(int num) 
        {
            if(m_tracker ==0) 
            {
                m_left.push(num);
                m_tracker = 1;
            }else if(m_tracker ==1)
            {
                if(m_left.top() > num )
                {
                    m_right.push(m_left.top());
                    m_left.pop();
                    m_left.push(num);
                }
                else
                {
                    m_right.push(num);
                }
                ++m_tracker;
            }
            else
            {
                if(num> m_right.top())
                {
                    m_right.push(num);
                    if(m_left.size()+1 < m_right.size())
                    {
                        m_left.push(m_right.top());
                        m_right.pop();
                    }
                }
                else
                {
                    m_left.push(num);
                    if(m_left.size() > m_right.size()+1)
                    {
                        m_right.push(m_left.top());
                        m_left.pop();
                    }
                }

                ++m_tracker;
            }    
        }
        
        double findMedian() 
        {
            double sol;
            if(m_tracker & 1) 
            {
                if(m_left.size()>m_right.size()) sol =m_left.top();
                else sol =m_right.top();
            } 
            else
            {
                double a = m_left.top(),b = m_right.top();
                sol = (a+b) /2;
            }
            return sol;
        }
private:
        maxHeap m_left;
        minHeap m_right;
        int m_tracker=0;
};


int main()
{


    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    std::cout<< obj->findMedian()<<'\n';
    obj->addNum(3);
    std::cout<< obj->findMedian();
    delete obj;
}