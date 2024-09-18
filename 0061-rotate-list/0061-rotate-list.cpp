class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;

        ListNode *ptr = head;
        int len = 1;
        while (ptr->next) {
            ptr = ptr->next;
            len++;
        }

        ptr->next = head;

        k = k % len;
        int steps_to_new_head = len - k;

        ListNode *new_tail = head;
        for (int i = 1; i < steps_to_new_head; i++) {
            new_tail = new_tail->next;
        }
        ListNode *new_head = new_tail->next;

        new_tail->next = nullptr;

        return new_head;
    }
};
