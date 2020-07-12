#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int right = nums.size();
        vector<int> res = {-1, -1};
        if(right == 0)
            return res;
        
        right = right - 1;
        int left = 0;

        int low_bound = 0;
        while(left < right){
            int mid = left + (right - left) / 2;
            //cout<<nums[mid]<<endl;
            if(nums[mid] >= target){
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        if(left == right && nums[left] == target){
            low_bound = left;
        }
        else{
            return res;
        }
        

        left = 0; right = nums.size()-1;
        int up_bound = right;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] <= target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        if(nums[right] == target){
            up_bound = right;
        }
        else{
            up_bound = -1;
        }

        res[0] = low_bound;
        res[1] = up_bound;

        return res;
    }
};

