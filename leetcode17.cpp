#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<char, string> d2c={
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
    vector<string> ret_vec;
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return ret_vec;
        string str="";
        myfunc(str, digits, 0);
        return ret_vec;
    }
private:
    void myfunc(string& str, string digits, int i){
        if(i == digits.length()){
            ret_vec.push_back(str);
            return;
        }

        for(auto e: d2c[digits[i]]){
            str.push_back(e);
            myfunc(str, digits, i+1);
            str.pop_back();
        }

        return;
    }
};