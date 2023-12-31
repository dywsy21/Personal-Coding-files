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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(0, head);
        bool done = true;
        while(1){
            done = true;
            ListNode* cur = dummy;
            while(cur->next && cur->next->next){
                if(cur->next->val >= x && cur->next->next->val < x){
                    swap(cur);
                    done = false;
                }
                cur = cur->next;
            }
            if(done) break;
        }
        return dummy->next;
    }
};