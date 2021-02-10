//
// Created by dianyuluo on 2021/2/4.
//

#include"iostream"
#include "string"

using namespace std;

class CaseInsensitiveStringHash{
public:
    size_t operator()(const string&s)const{
        static hash<string>hf;
        return hf(tolower(s));
    }
    bool operator()(const string &lhs,const string &rhs)const{
        return equalsIgnoreCase(lhs,rhs);
    }
};

int main() {
    cout<<"liannnn";
}