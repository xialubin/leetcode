#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<unordered_map>
#include<queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    struct cmp{
        bool operator()(ListNode* & a, ListNode* & b){
            if(a->val >= b->val)
                return true;
            else 
                return false;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(int i=0; i<lists.size(); i++){
            if(lists[i] != NULL)
                q.push(lists[i]);
        }

        ListNode* new_head = new ListNode(0);
        ListNode* node_r = new_head;
        while(!q.empty()){
            ListNode* node = q.top();
            q.pop();
            node_r->next = node;
            node = node->next;
            node_r = node_r->next;

            if(node != NULL){
                q.push(node);
            }
        }

        node_r = new_head->next;
        delete new_head;

        return node_r;
    }
};