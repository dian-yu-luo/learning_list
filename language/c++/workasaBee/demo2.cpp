#include "iostream"
#include "deque"
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
    deque<int> de;
    de.push_back()
}