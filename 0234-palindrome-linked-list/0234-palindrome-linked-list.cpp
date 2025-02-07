class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> stk;

        ListNode* fast = head;
        ListNode* slow = head;

        // Push first half of elements onto the stack
        while (fast && fast->next) {
            stk.push(slow->val);
            fast = fast->next->next;
            slow = slow->next;
        }

        // If odd number of elements, skip the middle one
        if (fast) slow = slow->next;

        // Compare stack with the second half of the list
        while (slow) {
            if (stk.top() != slow->val) return false;
            stk.pop();
            slow = slow->next;
        }

        return true;
    }
};
