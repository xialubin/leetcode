#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
private:
    int my_binary_search(vector<int>& nums, int target, int left, int right){
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int right = nums.size();
        if(right == 0)
            return -1;
        
        right = right-1;
        int left = 0;

        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid]<nums[right]){
                right = mid;
            }
            else{
                left  = mid+1;
            }
        }

        int rot = left;

        if(target > nums[nums.size()-1]){
            return my_binary_search(nums, target, 0, rot-1);
        }
        else if(target < nums[nums.size()-1]){
            return my_binary_search(nums, target, rot, nums.size()-1);
        }
        else{
            return nums.size()-1;
        }

    }
};