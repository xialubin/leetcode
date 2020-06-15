#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int alt[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int m=0, n=0;
    vector<int> next_cor(vector<int>& cor, int a){
        vector<int> r(2);
        r[0] = cor[0] + alt[a][0];
        r[1] = cor[1] + alt[a][1];
        return r;
    }
    int next_direction(int a){
        return (a+1)%4;
    }
    bool in_area(vector<int>& cor){
        if(cor[0]<m && cor[0]>=0 && cor[1]<n && cor[1]>=0 )
            return true;
        else
            return false;
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        m = matrix.size();
        if(m == 0)
            return res;
        n = matrix[0].size();
        if(n == 0)
            return res;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int derect = 0;
        vector<int> s = {0,0};
        visited[s[0]][s[1]] = true;
        res.push_back(matrix[s[0]][s[1]]);
        while(res.size()<m*n){
            vector<int> new_s = next_cor(s, derect);
            if(in_area(new_s) && !visited[new_s[0]][new_s[1]]){
                res.push_back(matrix[s[0]][s[1]]);
                s[0] = new_s[0];
                s[1] = new_s[1];
            }
            else{
                derect = next_direction(derect);
            }
        }
        return res;
    }
};

int main(){
    vector<int> a = {0, 0};
    Solution S;
    vector<int> new_a = S.next_cor(a, 0);
    bool b = S.in_area(new_a);
    cout<<b<<endl;
    system("pause");
    return 0;
}