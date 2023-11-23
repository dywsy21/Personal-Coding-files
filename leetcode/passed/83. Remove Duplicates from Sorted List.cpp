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
        if(!head || !head->next) return head;
        ListNode* cur = head;

        while(cur->next){
            ListNode* jump_to = cur;
            while(jump_to->next && jump_to->val == jump_to->next->val) jump_to = jump_to->next;
            if(jump_to != cur){
                if(jump_to->next) cur->next = jump_to->next;
                else cur->next = nullptr;
            }
            else cur = cur->next;
        }
        return head;
    }
};