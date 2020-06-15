#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<iterator>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        map<int, string> num2roman = {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"}
        };

        string res = "";
        map<int, string>::iterator iter;
        int c = 1000, digit = 0;
        while(c > 0){
            digit = (num / c) * c;
            while(digit>0){
                iter = num2roman.lower_bound(digit);
                if(iter == num2roman.end()){
                    res = res + num2roman[1000];
                    digit = digit - 1000;
                    //cout<<res<<endl;
                }
                else{
                    if(iter->first == digit){
                        res = res + iter->second;
                        //cout<<res<<endl;
                    }
                    else{
                        iter--;
                        res = res + iter->second;
                        //cout<<res<<endl;
                    }
                    digit = digit - iter->first;
                }
            }
            
            num = num % c;
            c = c / 10;
        }

        return res;

    }
};

int main(){
    int num = 1884;
    Solution S;
    cout<<S.intToRoman(1884)<<endl;

    system("pause");
    return 0;
}