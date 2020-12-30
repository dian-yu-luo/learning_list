//
// Created by 点雨落山岚 on 2020/12/29.
//
#include <iostream>
using namespace std;

class Object{
private:int e =1;
public:int c =2;
protected:int d = 3;

};

class Object_son: public Object{
    void fun(){
        cout<<d;
    }

};

int main(){

}
