#include<iostream>
class MinStack {
    int m_stack[30000];
    int m_Min;
    int m_Top;
public:
    MinStack() {
        m_Top=-1;
    }
    
    void push(int val) {
        if(m_Top<29999)
        {
            if(m_Top==-1) m_Min=val;
            else if(m_Min>val) m_Min=val;
            
            ++m_Top;
            m_stack[m_Top]=val;
            
        }
    }
    
    void pop() {
        if(m_Min==m_stack[m_Top] and m_Top!=0) 
        {
            m_Min=m_stack[m_Top-1];
            for(int i=0;i<m_Top;i++) if(m_Min>m_stack[i]) m_Min=m_stack[i];
        }
        --m_Top;
    }
    
    int top() {
        return m_stack[m_Top];
    }
    
    int getMin() {
        return m_Min;
    }
};

int main()
{
    MinStack *min = new MinStack();
    min->push(32);
    std::cout<<min->getMin()<<" <-  min || top -> "<<min->top()<<" \n";
    min->push(-21);
     min->push(1121);
        std::cout<<min->getMin()<<" <-  min || top -> "<<min->top()<<" \n";
    min->pop();
        std::cout<<min->getMin()<<" <-  min || top -> "<<min->top()<<" \n";
    min->pop();
    // min->pop();
    min->pop();
    min->push(89);
    std::cout<<min->getMin()<<" <-  min || top -> "<<min->top()<<" \n";
    delete min;
}