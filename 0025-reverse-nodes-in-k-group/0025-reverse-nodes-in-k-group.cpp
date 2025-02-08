class Solution {
public:
    ListNode* reverseKNodes(ListNode* head, int k) {
        ListNode *prev = nullptr, *curr = head, *next = nullptr;
        for (int i = 0; i < k && curr; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = curr; 
        return prev; 
    }

    ListNode* reverseList(ListNode* head, int k) {
        if (!head) return head;

        ListNode *ptr = head;
        int count = 0;
        while (ptr && count < k) {
            ptr = ptr->next;
            count++;
        }

        if (count < k) return head;
        ListNode *newHead = reverseKNodes(head, k);
        head->next = reverseList(head->next, k);
        
        return newHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseList(head, k);
    }
};
