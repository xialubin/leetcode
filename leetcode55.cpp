#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int left = nums.size() - 1;
        for (int i = nums.size()-1; i>=0; i--){
            if( (i + nums[i])>=left)
                left = i;
        }
        return left == 0;
    }
};