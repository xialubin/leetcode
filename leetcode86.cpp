#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include "limits.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* new_head = new ListNode(0);
        if(head == NULL) return head;
        ListNode* b = new_head;
        ListNode* p = new_head->next;
        ListNode* temp;

        while(head != NULL){
            if(head->val < x){
                temp = head;
                head = head->next;
                temp->next = b->next;
                b->next = temp;
                b = b->next;
            }
            else{  // head->val >= x
                temp = head;
                head = head->next;
                if(p == NULL){
                    temp->next = NULL;
                    p = temp;
                    b->next = p;
                }
                else{
                    temp->next = NULL;
                    p->next = temp;
                    p = p->next;
                }                
            }
        }
        
        head = new_head->next;
        delete new_head;
        return head;
        
    }
};