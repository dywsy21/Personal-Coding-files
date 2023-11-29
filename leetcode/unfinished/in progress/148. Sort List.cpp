#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void swap(ListNode* prev){ //prev->x->y, swap(x,y)
    if(!prev->next || !prev->next->next) return;
    ListNode* next_node = prev->next->next->next;
    ListNode* x = prev->next;
    ListNode* y = prev->next->next;
    prev->next = y;
    y->next = x;
    x->next = next_node;
}


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        auto dummy = new ListNode;
        dummy->next = head;
        while(1){
            auto temp = dummy;
            bool flag = true;
            while(temp->next && temp->next->next){
                if(temp->next->val > temp->next->next->val){
                    swap(temp);
                    flag = false;
                } 
                temp = temp->next;
            }
            if(flag) break;
        }
        return dummy->next;
    }
};

