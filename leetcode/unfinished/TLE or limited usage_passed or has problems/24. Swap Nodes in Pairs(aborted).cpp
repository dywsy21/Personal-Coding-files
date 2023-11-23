#include <bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};



//下面的方法不能使用，因为单向链表的连接指针被改变，会导致C++自动释放被断开节点的内存
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !(head->next)) return head;
        
        vector<ListNode*> nodes {};

        int n=0;
        while(head){
            nodes.push_back(head); //!!!  vector添加元素应该这么干
            head = head->next;
            n++;
        }
        

//每次操作：(2->1->4).....   2 1 4, 4 3 6, 6 5 8, ....
        for(int i=1; i<=n/2 ; i++){
            nodes[2*i-1]->next = nodes[2*i-1-1];
            if(2*i+2-1 <= n) nodes[2*i-1-1]->next = nodes[2*i+2-1];
        }
        return nodes[1];
    }
};