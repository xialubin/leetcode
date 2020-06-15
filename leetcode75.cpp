#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return;
        
        int i = -1, k = 0, j = n, p = n;
        while(k<p){
            if(nums[k] < 1){
                i++;
                k++;
            }
            else if(nums[k] == 1){
                swap(nums[p-1], nums[k]);
                p--;
            }
            else{  //nums[k] > 1
                swap(nums[p-1], nums[j-1]);
                p--;
                if(k == p)  //when k = p-1, only need to swap once
                    return;
                swap(nums[k], nums[j-1]);
                j--;
            }
        }

        return;
    }
};