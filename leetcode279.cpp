#include<vector>
#include<string>
#include<queue>
#include<iostream>

using namespace std;

class Solution {
private:
    int max_m(int n){
        int m=1;
        while(m*m <= n){
            m++;
        }
        return m-1;
    }
public:
    int numSquares(int n) {
        if(n == 0)
            return 0;
        int m;
        int front;
        int step;
        queue<pair<int, int>> q;
        q.push(make_pair(n, 0));
        vector<bool> visited(n+1, false);
        visited[n] = true;
        while(q.front().first != 0){
            front = q.front().first;
            step = q.front().second;
            //cout<<"front:" <<front<<"  "<<"step: "<<step<<endl;
            q.pop();
            //m = max_m(front);
            m = 1;
            //cout<<"m:" <<m<<endl;
            int push_num = front -m*m;
            while(push_num >= 0){
                
                if(!visited[push_num]){
                    q.push(make_pair(push_num, step+1));
                    visited[push_num] = true;
                }
                m ++;
                push_num = front - m*m;
            }
        }

        return q.front().second;

    }
};

int main(){
    Solution sol;
    int n = 13;
    int res = sol.numSquares(n);
    cout<<res<<endl;
    system("pause");
    return 0;
}