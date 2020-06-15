#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<char> myfunc(char a, char b, char c){
        vector<char> res;
        res.clear();
        int r = 0;
        r = (a-'0')+(b-'0')+(c-'0');
        res.push_back(('0' + r / 2));
        res.push_back(('0' + r % 2));
        return res;
    }
public:
    string addBinary(string a, string b) {
        string res;
        res.clear();
        int i = a.length()-1;
        int j = b.length()-1;
        char c='0';
        while(i>=0&&j>=0){
            vector<char> r = myfunc(a[i], b[j], c);
            c = r[0];
            res.insert(res.begin(), r[1]);
            i--;j--;
        }
        if(j>=0){
            while(j>=0){
                vector<char> r = myfunc(b[j], c, '0');
                c = r[0];
                res.insert(res.begin(), r[1]);
                j--;
            }
        }
        if(i>=0){
            while(i>=0){
                vector<char> r = myfunc(a[i], c, '0');
                c = r[0];
                res.insert(res.begin(), r[1]);
                i--;
            }
        }
        if(c == '1')
            res.insert(res.begin(), '1');
        
        return res;
    }
};