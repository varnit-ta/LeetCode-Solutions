class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;

        while (current != NULL) {
            int sum = 0;
            ListNode* runner = current->next;

            while (runner != NULL) {
                sum += runner->val;
                if (sum == 0) {
                    current->next = runner->next;
                }
                runner = runner->next;
            }

            current = current->next;
        }

        return dummy->next;
    }
};
