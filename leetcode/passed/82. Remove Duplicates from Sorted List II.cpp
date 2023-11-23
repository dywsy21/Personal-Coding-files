#include <bits/stdc++.h>
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* cur = head;

        while (cur) {
            ListNode* jump_to = cur;
            while (jump_to->next && jump_to->val == jump_to->next->val) {
                jump_to = jump_to->next;
            }
            if (jump_to != cur) {
                prev->next = jump_to->next;
            } else {
                prev = prev->next;
            }
            cur = prev->next;
        }

        return dummy->next;
    }
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        bool dup = false;
        while(head->next){
            if((head->next && head->val == head->next->val)){
                while((head->next && head->val == head->next->val)){
                    head = head->next;
                    dup = true;
                }
            }
            else{
                if(dup) head = head->next;
                break;
            }
        }
        if(!head || !head->next) return head;

        ListNode* cur = head;
        while(cur->next){
            ListNode* temp = cur;
            while((cur->next && cur->val == cur->next->val) || (cur->next && cur->next->next && cur->next->val == cur->next->next->val))
                cur = cur->next;
            if(cur != temp) temp->next = cur->next;
            cur = cur->next;
        }
        return head;
    }
};