//
// Created by dianyuluo on 2021/1/24.
//

#include"iostream"
#include "stack"
#include "string"

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char ch:s) {
            if (ch == ')' || ch == '}' || ch == ']') {
                if (stk.empty()) {
                    return false;
                } else{
                    if(ch==')'&&stk.top()=='('){
                        stk.pop();
                    } else if (ch=='}'&&stk.top()=='{'){
                        stk.pop();
                    } else if(ch==']'&&stk.top()=='['){
                        stk.pop();
                    } else {
                        return false;
                    }
                }
            } else{
                stk.push(ch);
            }

        }
        return stk.empty();

    }
};


int main() {
    cout << "lianaldfasg" << endl;
}