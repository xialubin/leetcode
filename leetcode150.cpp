#include<iostream>
#include<stack>
#include<vector>
#include<string>

using namespace std;

class Solution {
private:
    int stringtoint(string str){
        int len = str.length();
        if(len == 0)
            return 0;
        int flag=1;
        int res = 0;
        for(int i=0;i<len;i++){
            if(i == 0 && (str[i]>'9' || str[i]<'0'))
                flag = -1;
            else{
                res = res*10 + str[i];
            }
        }
        return (res*flag);
    }
public:
    int evalRPN(vector<string>& tokens) {
        int len = tokens.size();
        if(len == 0)
            return 0;
        stack<int> nums;
        int a,b;
        for(int i=0;i<len;i++){
            string temp = tokens[i];
            if(temp != "+" && temp != "-" && temp != "/" && temp != "*")
                nums.push(stoi(temp));
            else{
                a = nums.top();nums.pop();
                b = nums.top();nums.pop();
                if(temp == "+")
                    nums.push((a+b));
                if(temp == "-")
                    nums.push((b-a));
                if(temp == "/")
                    nums.push((b/a));
                if(temp == "*")
                    nums.push((a*b));
            }
        }
        
        int res=nums.top();
        return res;
        
    }
};