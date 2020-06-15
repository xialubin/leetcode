#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

class Solution {
private:
    bool ismirror(TreeNode* t1, TreeNode* t2){
        if(t1 == NULL && t2 == NULL)
            return true;
        if(t1 == NULL ^ t2 == NULL)
            return false;
        return (t1->val == t2->val) && ismirror(t1->left, t2->right) && ismirror(t1->right, t2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        // Recursive
        //bool res = true;
        //res = ismirror(root, root);
        //return res;

        // Iterative
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while(!q.empty()){
            TreeNode *t1 = q.front();
            q.pop();
            TreeNode *t2 = q.front();
            q.pop();
            if(t1 == NULL && t2 == NULL) continue;
            if(t1 == NULL ^ t2 == NULL) return false;
            if(t1->val != t2->val) return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }

        return true;
    }
};

int main(){
    bool a = true;
    bool b = true;
    bool c = a ^ b;
    cout<<c<<endl;
    system("pause");
    return 0;
}