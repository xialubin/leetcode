#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<limits.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> set;
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4)
            return res;
        sort(nums.begin(), nums.end());
        kSum(nums, target, 0, 4);

        return res;
    }
private:
    void kSum(vector<int>& nums, int target, int start, int k){
        if(start > nums.size()-k || nums[start]*k > target || nums[nums.size()-1]*k < target)
            return;
        if(k == 2){
            twoSum(nums, target, start);
            return;
        }
        for(int i=start; i<nums.size(); i++){
            if(i == start || nums[i] != nums[i-1]){
                set.push_back(nums[i]);
                kSum(nums, target-nums[i], i+1, k-1);
                set.pop_back();
            }
        }
        return;
        
    }

    void twoSum(vector<int>& nums, int target, int start){
        int l = start;
        int r = nums.size() -1;
        while(l < r){
            int sum = nums[l] + nums[r];
            if(sum > target || (r<nums.size()-1 && nums[r] == nums[r+1]))
                r--;
            else if(sum < target || (l>0 && nums[l] == nums[l-1]))
                l++;
            else{
                res.push_back(set);
                res.back().push_back(nums[l]);
                res.back().push_back(nums[r]);
                l++;r--;
            }
        }
        return;
    }
};

int main(){
    vector<int> nums={-2,-1,0,0,1,2};
    Solution S;
    vector<vector<int>> res = S.fourSum(nums, 0);

    system("pause");
    return 0;
}