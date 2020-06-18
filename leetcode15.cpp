#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vec_ret;
        int n = nums.size();
        if(n < 3)
            return vec_ret;

        sort(nums.begin(), nums.end());
        if(nums[0] > 0 || nums[n-1] < 0)
            return vec_ret;

        vector<int> cur = {0, 0, 0};
        for(int i=0; i<n-2; i++){
            if(nums[i] > 0)
                break;
            int j=i+1;
            int c = 0 - nums[i];
            for(; j<n-1; j++){
                if(nums[j] > c)
                    break;
                if(binary_search(nums.begin()+j+1, nums.end(), (c-nums[j]))){
                    cur[0]=nums[i];cur[1]=nums[j];cur[2]=c-nums[j];
                    vec_ret.push_back(cur);
                    while(j<n-1 && nums[j] == nums[j+1])
                        j++;
                }
            }
            while(i<n-1 && nums[i] == nums[i+1])
                i++;
        }

        return vec_ret;
    }
};