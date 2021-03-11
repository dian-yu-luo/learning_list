//
// Created by dianyuluo on 2021/3/9.
//
#include<iostream>
#include "vector"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int Max = nums[0];
        int temp;
        int Size=int (nums.size());
        for (int i = 0; i < Size; ++i) {
            temp = nums[i];
            for (int j = 0; j < Size - i; ++j) {
                if (Max < temp) {
                    Max = temp;
                }
                temp += nums[i + j + 1];
            }
        }
        return Max;
    }
};

int main() {
    cout << "liangad";
}