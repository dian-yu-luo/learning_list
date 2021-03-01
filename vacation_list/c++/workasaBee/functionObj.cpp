//
// Created by dianyuluo on 2021/2/3.
//
#include "vector"
#include "iostream"

using namespace std;

template<typename Object, typename Comparator>
const Object &findMax(const vector<Object> &arr, Comparator cmp) {
    int maxIndex = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (cmp.isLessThan(arr[maxIndex], arr[i])) {
            maxIndex = 1;
        }
        return arr[maxIndex];
    }
}

class CaseinsensitiveCompare {
public:
            bool islessthan(const string &lhs,const string&rhs)cosnt{
                return
            }
};
int main(){
    vector<string >arr={"zeff","asdfj","kozcvub"};
    cout<<findMax(arr,CaseinsensitiveCompare())<<endl;
}