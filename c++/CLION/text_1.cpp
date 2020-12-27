#include <iostream>
using namespace std;

class obj{
public:

private:
    int a;
    int *b;
    obj* c;
};

int main(){

    const int a=0;
    //a=2;
    const * int b =&a;
    cout<<a;
}