#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct mypair
{
    TreeNode* node;
    int l;
    mypair(TreeNode* node, int x): node(node), l(x) {}
};

 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        queue<mypair> q;
        q.push(mypair(root, 0));
        while(!q.empty()){
            TreeNode* node = q.front().node;
            int level = q.front().l;
            q.pop();

            if(level == res.size())
                res.push_back(vector<int>());
            
            res[level].push_back(node->val);
            if(node->left)
                q.push(mypair(node->left, level+1));
            if(node->right)
                q.push(mypair(node->right, level+1));
        }

        return res;
        
    }
};