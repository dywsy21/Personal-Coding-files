#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> node_map;
        Node* ret = head;
        Node* cur = head;
        while(head){
            node_map[head] = new Node(head->val);
            head = head->next;
        }

        while(cur){
            node_map[cur]->random = node_map[cur->random];
            node_map[cur]->next = node_map[cur->next];
            cur = cur->next;
        }

        return node_map[ret];
    }
};