#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> parentheses = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> P_store;
        for(auto e:s){
            if(e == '(' || e == '[' || e == '{')
                P_store.push(e);
            else {
                if(!P_store.empty() && P_store.top() == parentheses[e]){
                    P_store.pop();
                }
                else
                    return false;
            }
        }

        if(P_store.size() == 0)
            return true;
        else 
            return false;
    }
};