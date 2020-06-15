#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=-1;
        int max_len = 0;
        unordered_map<char, int> letter_pos;
        char letter;
        for(int e=0; e<s.length(); e++){
            letter = s[e];
            if(letter_pos.find(letter) == letter_pos.end()){
                letter_pos.insert(pair<char, int>(letter, e));
                //j++;
            }
            else{
                if(letter_pos[letter]<=i){
                    letter_pos[letter] = e;
                    //j++;
                }
                else{
                    i = letter_pos[letter];
                    letter_pos[letter] = e;
                }
            }
            max_len = ((e - i)>max_len) ? (e - i) : max_len;
        }

        return max_len;
    }
};

int main(){
    string ss;
    int res;
    while(cin >> ss){
        Solution S;
        res = S.lengthOfLongestSubstring(ss);
        cout << res << endl;
    }
    system("pause");
    return 0;
}