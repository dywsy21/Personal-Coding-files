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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }
        
        int n = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            n++;
        }
        
        k %= n;
        if (k == 0) {
            return head;
        }
        
        ListNode* newTail = head;
        for (int i = 0; i < n - k - 1; i++) {
            newTail = newTail->next;
        }
        
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;
        
        return newHead;
    }
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || !k) return head;
        int n {1};
        ListNode* tail = head;
        while(tail->next){
            tail = tail->next;
            n++;
        }
        k %= n;

        tail->next = head;
        ListNode* new_tail = head;
        for(size_t i = 0; i < n - k - 1; i++)
            new_tail = new_tail->next;
        ListNode* new_head = new_tail->next;
        new_tail->next = nullptr;
        return new_head;
    }
};