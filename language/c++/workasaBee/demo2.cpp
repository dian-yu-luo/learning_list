#include "iostream"
using namespace std;

class  folwerror{
public:
    folwerror(){
        printf("llllll");
    }
};

void func(int a){
    if (a==1)
        throw folwerror{};
    printf("aaaa");
}

int main(){
    cout<<endl<<" ";
    func(1);
    cout<<"liang";
    cout<<"liang";
    cout<<"liang";
    cout<<"liang";
    cout<<"liang";
    cout<<"liang";

}