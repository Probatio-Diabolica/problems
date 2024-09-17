#include<iostream>
#include<vector>
using namespace std;

class Test{
    private:
    int x=0,y=0;
    public:
        int a,b;
        Test(int a,int b):x(a),y(b)
        {
            this->a=a;
            this->b=b;
        }
        void hello(){
            cout << this->a<<endl;
        }
};

int main(){
    Test test=Test(10,11);
    Test testb=Test(12,14);
    vector<Test> abc= {};
    
    abc.push_back(test);
    abc.push_back(testb);
    abc[0].hello();
    abc[1].hello();
    
    return 0;
}