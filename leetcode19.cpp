#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* node_i = new_head->next;
        int len=0;
        while(node_i!=NULL){
            node_i=node_i->next;
            len++;
        }
        node_i = new_head;
        int i=1;
        while(i < (len-n+1)){
            node_i = node_i->next;
            i++;
        }
        ListNode* node_rm = node_i->next;
        node_i->next = node_rm->next;

        ListNode* re_head = new_head->next;
        delete node_rm;
        delete new_head;

        return re_head;
    }
};