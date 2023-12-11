struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(!head || !head->next) return head;
    struct ListNode* cur = head;

    while(cur->next){
        struct ListNode* jump_to = cur;
        while(jump_to->next && jump_to->val == jump_to->next->val) jump_to = jump_to->next;
        if(jump_to != cur){
            if(jump_to->next) cur->next = jump_to->next;
            else cur->next = NULL;
        }
        else cur = cur->next;
    }

    return head;
}










