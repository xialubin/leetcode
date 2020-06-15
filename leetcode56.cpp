#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool cmp(vector<int> a, vector<int> b){
        if(a[0] != b[0])
            return a[0] < b[0];
        else
            return a[1] < b[1]; 
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        res.clear();
        if (intervals.size() == 0)
            return res;
        sort(intervals.begin(), intervals.end(), cmp);
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size()-1;i++){
            if(intervals[i][0] > res[res.size()-1][1])
                res.push_back(intervals[i]);
            else{
                if(res[res.size()-1][1] < intervals[i][1])
                    res[res.size()-1][1] = intervals[i][1];
            }
        }
        return res;
    }
};