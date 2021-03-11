//
// Created by dianyuluo on 2021/3/1.
//

#include"iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int Maxsum=0;
        int sum;
        int Size=nums.size();
        for (int i = 0; i < Size; ++i) {
            sum=nums[i];
            {
                if (Maxsum<sum){
                    Maxsum=sum;
                }
            }
            for (int j = 0; (i+j)!=Size; ++j) {
                sum+=nums[i+j+1];
                if (Maxsum<sum){
                    Maxsum=sum;
                }
            }
        }
        return Maxsum;
    }
};

int main() {
    cout << "liawenjianng" << endl;
}