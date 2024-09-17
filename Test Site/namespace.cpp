#include<iostream>

namespace hello
{
    void show(){
        std::cout<<"HELLO"<<std::endl;
    }
} // namespace hello

namespace BF4
{
    class Solution{
        public:
            void warsaw(){
                std::cout<<"Dum dum dum duu dum du"<<std::endl;
            }
    };
} // namespace BF4

// namespace test3
// {
//     class N{
//         private:
//             int a,b;
//         public:
//             N(int x,int y){
//                 a=x;
//                 b=y;
//             }
//             void show(){
                
//                 std::cout<<this->a;
//             }
//     };
// } // namespace test3

using namespace std;
int main(){

    hello::show();
    
    BF4::Solution sol;
    sol.warsaw();
    // test3::N n; 
    // n.show();
    return 0;
}
