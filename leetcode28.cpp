#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> build_nxt(string needle){
        vector<int> next(needle.length());

        int x = 1;
        while(x < needle.length()){
            int now = next[x-1];
            if(needle[now] == needle[x]){
                next[x] = next[x-1] + 1;
            }
            else{
                while(now != 0 && needle[now] != needle[x]){
                    now = next[now-1];
                }
                if(needle[now] == needle[x])
                    next[x] = now+1;
                else{
                    next[x] = now;
                }
            }
            x ++;
        }

        return next;
    }
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0)
            return 0;

        vector<int> next = build_nxt(needle);
        int i=0, j=0;
        while(i < haystack.length() && j < needle.length()){
            if(haystack[i] == needle[j]){
                i++;j++;
            }
            else{
                if(j != 0)
                    j = next[j-1];
                else 
                    i++;
            }
        }

        if(j == needle.length())
            return i-j;
        else 
            return -1;
        
    }
};


int main(){
    string needle = "bba";
    string hstr = "aaaaa";

    Solution S;
    vector<int> next = S.build_nxt(needle);

    for(auto e:next){
        cout<<e<<endl;
    }
    cout<<S.strStr(hstr, needle)<<endl;

    system("pause");
    return 0;
}