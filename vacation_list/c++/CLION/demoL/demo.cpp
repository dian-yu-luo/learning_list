#include<iostream>
using namespace std;
int main(){
    int a[10];
    for (size_t i = 0; i < 10; i++)
    {
        a[i]=i+1;
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int b;
    cin>>b;
    cout<<a[b];
}