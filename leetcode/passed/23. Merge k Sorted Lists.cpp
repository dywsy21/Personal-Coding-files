#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(0);
    ListNode* current_node = dummy;

        while(list1 && list2){
            if(list1->val <= list2->val){
                current_node->next = list1;
                list1 = list1->next;
            }
            else{
                current_node->next = list2;
                list2 = list2->next;
            }
            current_node = current_node->next;
        }  

        current_node->next = list1? list1:list2;
        return dummy->next;

}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        if(lists.size()==1) return lists[0];

        ListNode* ret_node = mergeTwoLists(lists[0],lists[1]);
        for(int i=2; i<lists.size(); i++){
            ret_node = mergeTwoLists(ret_node,lists[i]);
        }
        return ret_node;
    }




};