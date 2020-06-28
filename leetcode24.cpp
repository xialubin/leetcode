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
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* node0 = new_head;
        ListNode* node1 = head;
        if(head == NULL)
            return head;
        ListNode* node2 = head->next;

        while(node1 != NULL && node2 != NULL){
            node1->next = node2->next;
            node0->next = node2;
            node2->next = node1;
            node0 = node1;
            node1 = node0->next;
            if(node1 == NULL)
                node2 = NULL;
            else 
                node2 = node1->next;
        }

        head = new_head->next;
        delete new_head;
        return head;
    }
};