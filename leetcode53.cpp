#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int len = nums.size();
//         if(len == 0)
//             return 0;
//         int max_sum = nums[0];
//         int max_sum_endhere = nums[0];
//         for(int i=1;i<len;i++){
//             max_sum_endhere = max(nums[i], max_sum_endhere + nums[i]);
//             max_sum = max(max_sum, max_sum_endhere);
//         }
//         return max_sum;
//     }
// };

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        int max_sum = maxSubArray(nums, 0, len-1);
        return max_sum;
    }
private:
    int maxSubArray(vector<int>& nums, int l, int r){
        if(l>r)
            return INT_MIN;
        int mid = l + (r-l) / 2, ml=0, mr=0;
        int lmax = maxSubArray(nums, l, mid-1);
        int rmax = maxSubArray(nums, mid+1, r);
        for(int i=mid-1, sum=0; i>=l; i--){
            sum += nums[i];
            ml = max(ml, sum);
        }
        for(int i=mid+1, sum=0; i<=r; i++){
            sum += nums[i];
            mr = max(mr, sum);
        }
        return max(max(lmax, rmax), (ml+mr+nums[mid]));
    }
};