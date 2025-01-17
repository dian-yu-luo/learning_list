//
// Created by dianyuluo on 2021/1/24.
//
#include "iostream"
#include "stack"
#include "unordered_map"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }
        unordered_map<char, char> pairs = {
                {')', '('},
                {']', '['},
                {'}', '{'}
        };
        stack<char> stk;
        for (char ch:s) {
            if (pairs.count(ch)) {
                if(stk.empty()||stk.top()!=pairs[ch]){
                    return false;
                } else{
                    stk.pop();
                }

            } else{
                stk.push(ch);
            }
        }
        return stk.empty();

    }
};

int main() {

}

