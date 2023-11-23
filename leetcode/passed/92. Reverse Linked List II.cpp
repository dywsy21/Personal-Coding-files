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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;
        ListNode* left_node = new ListNode();
        ListNode* right_node = head;
        ListNode* left_temp = new ListNode(0, head);
        for(int i = 1; i < left; i++) left_temp = left_temp->next;
        left_node = left_temp->next;
        for(int i = 1; i < right; i++) right_node = right_node->next;

        ListNode* right_temp = right_node->next;
        left_temp->next = right_node;

        for(int i = 1; i <= right - left; i++){
            ListNode* cur = left_node;
            for(int j = 1; j <= right- left - i; j++) cur = cur->next;
            cur->next->next = cur;
        }

        left_node->next = right_temp;
        return left == 1 ? right_node : head;
    }
};