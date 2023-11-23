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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* test;
            ListNode* cache_head = head;
            int size = 0;
            while(cache_head){
                cache_head = cache_head->next;
                size++;
            }
            if(!size) return nullptr;
            if(size == n) return head->next;

    //找到被删除元素之前的那个元素，现在一定存在了
            cache_head = head;
            int nexts = 2;
            while(nexts <= size - n) {
                cache_head = cache_head->next;
                nexts++;
            }

            if((cache_head->next)->next) cache_head->next = (cache_head->next)->next;
            else cache_head->next = nullptr;
            
            return head;
        }
    };
int main() {
    Solution solu;
    system("pause");
    return 0;
}