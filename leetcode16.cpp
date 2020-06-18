#include<vector>
#include<algorithm>
#include<iostream>
#include<limits.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int c_target=0;
        int diff = INT_MAX;
        int ret = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            int k = i+1;
            int q = nums.size()-1;
            c_target = target - nums[i];
            while(k < q){
                int sum_two = nums[k] + nums[q];
                if(abs(sum_two-c_target)<diff){
                    diff = abs(sum_two - c_target);
                    ret = sum_two + nums[i];
                }
                if(k == q)
                    break;
                if(sum_two > c_target){
                    q--;
                }
                else if(sum_two < c_target){
                    k++;
                }
                else{
                    return target;
                }
            }
        }

        return ret;
    }
};