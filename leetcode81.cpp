#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)
            return false;
        int low = 0, high = n-1;
        while(low<high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == nums[high]){
                while((low < n-1) && nums[low] == nums[low+1]){low ++;}
                while((high > 0) && nums[high] == nums[high-1]){high--;}
            }
            else if(nums[mid] > nums[high])
                low = mid + 1;
            else 
                high = mid;
        }

        int rot = low;
        cout<<rot<<endl;
        if(target > nums[n-1]){
            low = 0;
            high = rot - 1;
        }
        else if(target < nums[n-1]){
            low = rot;
            high = n-1;
        }
        else
            return true;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] > target)
                high = mid - 1;
            else if(nums[mid] < target)
                low = mid + 1;
            else 
                return true;
        }

        return false;
    }
};