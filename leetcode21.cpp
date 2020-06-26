#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* node = head;
        ListNode* p = l1;
        ListNode* q = l2;
        while(q != NULL && p != NULL){
            if(q->val < p->val){
                node->next = q;
                q = q->next;
                node = node->next;
            }
            else{
                node->next = p;
                p = p->next;
                node = node->next;
            }
        }

        if(q != NULL){
            node->next = q;
        }
        if(p != NULL){
            node->next = p;
        }

        ListNode* re_head = head->next;
        delete head;

        return re_head;
    }
};