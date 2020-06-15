#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<iterator>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman2num = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int n = s.length();

        int res = 0;
        for(int i=(n-1); i>=0; i--){
            if(i == (n-1))
                res += roman2num[s[i]];
            else{
                if(roman2num[s[i]] >= roman2num[s[i+1]])
                    res += roman2num[s[i]];
                else 
                    res -= roman2num[s[i]];
            }
        }

        return res;
    }
};