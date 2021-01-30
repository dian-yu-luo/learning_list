//
// Created by dianyuluo on 2021/1/24.
//

#include "iostream"
#include "stack"
#include "string"
#include "list"
#include "unordered_map"

using namespace std;

int main() {
    unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
    };
    string s="(){}[]";
    for(char ch :s){
        cout<<pairs.count(ch)<<endl;
    }
}