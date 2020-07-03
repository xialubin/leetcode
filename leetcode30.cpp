#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(s.length() == 0 || words.size() == 0)
            return res;

        int s_len = s.length(), word_len = words[0].length(), words_num = words.size();
        unordered_map<string, int> m1;
        for(int i=0; i<words_num; i++){
            if(m1.find(words[i]) == m1.end())
                m1.insert(make_pair(words[i], 1));
            else 
                m1[words[i]]++;
        }

        for(int i=0; i<word_len; i++){
            unordered_map<string, int> m2;
            int num = 0;
            string word;
            for(int j=i; j<s_len; j = j+word_len){
                word = s.substr(j, word_len);
                if(m1.count(word)){
                    m2[word]++;
                    num ++;
                    while(m2[word] > m1[word]){
                        int pos = j - word_len * (num - 1);
                        string rem_word = s.substr(pos, word_len);
                        m2[rem_word]--;
                        num--;
                    }
                }
                else{
                    num = 0;
                    m2.clear();
                }
                if(num == words_num){
                    res.push_back(j-word_len*(num-1));
                }
            }
        }

        return res;
    }
};
