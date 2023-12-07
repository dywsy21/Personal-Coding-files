struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(!head || !head->next || !k) return head;
    int n = 1;
    struct ListNode* tail = head;
    while(tail->next){
        tail = tail->next;
        n++;
    }
    k %= n;

    tail->next = head;
    struct ListNode* new_tail = head;
    for(size_t i = 0; i < n - k - 1; i++)
        new_tail = new_tail->next;
    struct ListNode* new_head = new_tail->next;
    new_tail->next = NULL;
    return new_head;
}