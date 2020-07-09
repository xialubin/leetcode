#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int i = len-1;
        while(i>=1 && nums[i] <= nums[i-1]){
            i--;
        }
        if(i == 0){
            reverse(nums.begin(), nums.end());
            return;
        }

        int j = i;
        while(j<len && nums[j] > nums[i-1]){
            j++;
        }
        j = j-1;

        swap(nums[i-1], nums[j]);
        reverse(nums.begin()+i, nums.end());

        return;
    }
};