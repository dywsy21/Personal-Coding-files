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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //在l1的位置上原地修改，以生成ans链表
            int flag = 0; //0->不进位，1->进位；用于l1长度<=l2长度且到末尾时使用
            ListNode* ret = l1;
            ListNode* cache = new ListNode();
            while(l1 && l2){
                flag = 0;
                if(l1->val + l2->val>=10){
                    l1->val = l1->val + l2->val -10;
                    if(l1->next) (l1->next)->val ++;
                    else if(l2->next) (l2->next)->val ++;
                    flag = 1;
                }
                else{
                    l1->val = l1->val + l2->val;
                }
                cache = l1;
                l1 = l1->next;
                l2 = l2->next;
            }

            if(l1==nullptr && l2==nullptr && flag){   //（****）
                ListNode* last_node = new ListNode(1);
                cache->next = last_node;
            }

            if(l2){
                cache->next = l2; 
                l1 = l2;
            }

            while (l1) {
                flag = 0;
                if (l1->val == 10) {
                    if (l1->next) (l1->next)->val++;
                    l1->val = 0;
                    flag = 1;
                }
                if (l1->next) {
                    l1 = l1->next;
                } else {
                    if (flag) {
                        ListNode* last_node = new ListNode(1);
                        l1->next = last_node;
                        flag = 0;
                    }
                    break;
                }
            }

            return ret;
        }
    };