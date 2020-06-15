#include<stack>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> folder_stack;
        stringstream ss {path};
        string tmp;
        
        while (getline(ss, tmp, '/')) {
            if ("" == tmp || "." == tmp) {
                continue;
            } else if (".." == tmp && !folder_stack.empty()) {
                folder_stack.pop();
            } else if (".." != tmp){
                folder_stack.push(move(tmp));
            }
        }
        
        string res;
        while(!folder_stack.empty()){
            res = "/" + folder_stack.top() + res;
            //cout<<folder_stack.top()<<endl;
            folder_stack.pop();
        }
        return res.empty()?  "/" : res;
    }
};


int main(){
    stack<int> a;
    int f = a.empty();
    //int b = a.top();
    cout<<f<<endl;
    system("pause");
    return 0;
}