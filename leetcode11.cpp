#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if(n <= 1)
            return 0;
        
        int i=0, j=n-1;
        int max_water = 0;
        while(i<j){
            max_water = max(max_water, min(height[i], height[j])*(j-i));
            if(height[i] < height[j])
                i++;
            else 
                j--;
        }

        return max_water;
    }
};