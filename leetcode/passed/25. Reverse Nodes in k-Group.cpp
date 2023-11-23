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
    ListNode* reverseKGroup(ListNode* head, int k) {

        vector<ListNode*> cache {};
        ListNode* cache_head = head;
        if(!head) return head;

        for(int i=0; i<k; i++){
            cache.push_back(cache_head);
            cache_head = cache_head->next;
            if(cache_head == nullptr && i<k-1) return head;
        }

        cache[0]->next = reverseKGroup(cache[k-1]->next,k);
        for(int i=1; i<k; i++) cache[i]->next = cache[i-1];
        return cache[k-1];
    }
};