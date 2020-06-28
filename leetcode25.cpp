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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
            return head;
        if(k == 1)
            return head;
        
        ListNode* new_head = new ListNode(0);
        ListNode* node0 = new_head;
        node0->next = head;
        ListNode* node1 = head;
        ListNode* node2 = node1->next;
        
        
        int i = 1;
        while(node1 != NULL && node2 != NULL){
            while(i<k && node1 != NULL && node2 != NULL){
                node1->next = node2->next;
                node2->next = node0->next;
                node0->next = node2;
                node2 = node1->next;
                i++;
            }
            if(i < k){
                node1 = node0->next;
                node2 = node1->next;
                i = 1;
                //cout<<"node0: "<<node0->val<<" node1: "<<node1->val<<" node2: "<<node2->val<<endl;
                while(i<k && node1 != NULL && node2 != NULL){
                    node1->next = node2->next;
                    node2->next = node0->next;
                    node0->next = node2;
                    node2 = node1->next;
                    i++;
                }
            }
            node0 = node1;
            if(node0 != NULL)
                node1 = node0->next;
            else 
                node1 = NULL;
            if(node1 != NULL)
                node2 = node1->next;
            else 
                node2 = NULL;
            i = 1;
        }

        head = new_head->next;
        delete new_head;
        return head;

    }
};