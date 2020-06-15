#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int len = intervals.size();
        vector<vector<int>> res;
        if(len == 0){
            res.push_back(newInterval);
            return res;
        }

        int left = 0, right = len-1;
        for(int i=0;i<len;i++){
            if(intervals[i][1] >= newInterval[0])
                break;
            left ++;
        }
        for(int i=len-1;i>=0;i--){
            if(intervals[i][0] <= newInterval[1])
                break;
            right --;
        }
        if(left >= len){
            intervals.push_back(newInterval);
            return intervals;
        }
        if(right < 0){
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }

        vector<int> new_inter = {min(intervals[left][0], newInterval[0]), max(intervals[right][1], newInterval[1])};
        for(int i=0; i<left; i++){
            res.push_back(intervals[i]);
        }
        res.push_back(new_inter);
        for(int i=right+1; i<len; i++){
            res.push_back(intervals[i]);
        }

        return res;
    }
};