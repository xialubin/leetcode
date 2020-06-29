#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
            return nums.size();

        int i=0, j=0;
        while(j<nums.size()){
            if(nums[j] != val){
                nums[i] = nums[j];
                i++;
                j++;
            }
            else {
                j++;
            }
        }

        return (i+1);
    }
};