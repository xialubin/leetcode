#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include "limits.h"
#include<stack>

using namespace std;

class Solution {
public:
    void myfunc(vector<string>& res, string& res_in, string s, int remain){
        if(s.length()>(remain*3))
            return;
        //if(s[0]-'0'>2)
            //return;
        if(remain == 0 && s.length() == 0){
            res.push_back(res_in);
            return;
        }
        if(remain == 0 && s.length() != 0){
            return;
        }
        int len = 3;
        for(int i=1; i<=len; i++){
            if(s[0]-'0' == 0)
                len = 1;
            if(i > s.length())
                break;
            string tmp = s.substr(0, i);
            if(stoi(tmp) > 255)
                break;
            res_in = res_in + tmp;
            if(remain >1)
                res_in = res_in + ".";
            //cout<<res_in<<endl;
            myfunc(res, res_in, s.substr(i), remain-1);
            if(remain > 1)
                res_in.pop_back();
            for(int j=0; j<i; j++)
                res_in.pop_back();
        }
        
        return;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        int remain = 4;
        vector<string> res;
        string res_in;
        res_in.clear();
        myfunc(res, res_in, s, remain);

        return res;

    }
};