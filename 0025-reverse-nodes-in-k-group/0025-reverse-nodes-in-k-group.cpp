class Solution {
public:
    // Reverse the first k nodes in-place
    ListNode* reverseKNodes(ListNode* head, int k) {
        ListNode *prev = nullptr, *curr = head, *next = nullptr;
        for (int i = 0; i < k && curr; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = curr; // Link to the next part
        return prev; // New head of the reversed k-group
    }

    ListNode* reverseList(ListNode* head, int k) {
        if (!head) return head;

        // Check if there are at least k nodes to reverse
        ListNode *ptr = head;
        int count = 0;
        while (ptr && count < k) {
            ptr = ptr->next;
            count++;
        }

        if (count < k) return head; // If less than k nodes, return as is

        // Reverse first k nodes
        ListNode *newHead = reverseKNodes(head, k);
        
        // Recursively reverse the remaining groups
        head->next = reverseList(head->next, k);
        
        return newHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseList(head, k);
    }
};
