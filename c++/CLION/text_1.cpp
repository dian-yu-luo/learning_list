#include <iostream>
#include <vector>
using namespace std;

class obj{

};

int main(){
    int i=1;
    cout<<i<<endl;
    i++;
    cout<<i<<endl;
    int *a=&i;
    cout<<*a<<endl;
    cout<<*a++<<endl;
    cout<<*a<<endl;
}