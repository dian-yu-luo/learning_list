//
// Created by dianyuluo on 2021/3/15.
//
#include<iostream>
#include "vector"

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int> &arr, int k) {
        int m = 0;
        for (int i = 0; i < arr.size(); ++i) {

            if (arr[m] == i) {
                m++;
            } else{
                k--;
            }
            if (k == 0) {
                return i;
            }
        }
    }
};

int main() {
    cout << "wen" << endl;
}
