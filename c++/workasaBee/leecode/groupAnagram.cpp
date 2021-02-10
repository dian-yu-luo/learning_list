//
// Created by dianyuluo on 2021/2/4.
//

#include"iostream"
#include "vector"
#include "map"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string index;
        vector<vector<string>> vecreturn;
        map<string ,vector<string>>dict;
        for(auto &str:strs){
            index=sortString(str);
            dict[index].push_back(str);
        }
        for(auto &thispair:dict){
            vecreturn.push_back(thispair.second);
        }
        return vecreturn;

    }


    string sortString(string str) {
        char c;
        for (int i = 0; i < str.length(); ++i) {
            for (int j = 0; j < str.length()-i-1; ++j) {
                if (int(str[j])>int(str[j+1])){
                    c=str[j];
                    str[j]=str[j+1];
                    str[j+1]=c;
                }
            }
        }
        return str;
    }
};

int main() {
    cout << "liang" << endl;
}