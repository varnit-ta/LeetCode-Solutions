class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1, head);

        ListNode *start = dummy;
        for (int i = 1; i < left; i++) start = start->next;

        ListNode* ptr = start->next;
        ListNode* prev = nullptr;

        for (int i = 0; i < (right - left + 1); i++) {
            ListNode* temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = temp;
        }

        start->next->next = ptr;
        start->next = prev; 

        return dummy->next;
    }
};