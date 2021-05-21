//
// Created by dianyuluo on 2021/3/9.
//

#include "vector"
#include "iostream"
#include "math.h"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int Max = nums[0];
        int temp;
        int Size = int(nums.size());
        for (int i = 0; i < Size; ++i) {
            temp = nums[i];
            for (int j = 0; j < Size - i; ++j) {
                if (Max < temp) {
                    Max = temp;
                }
                int k = i + j + 1;
                if ((i + j + 1) != nums.size()) { temp += nums[i + j + 1]; }
            }
        }
        return Max;
    }
};

class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};


int main() {
    int a = 1;
    int b = 2;
    cout<<max(a, b);


}