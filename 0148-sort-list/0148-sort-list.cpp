class Solution {
public:
    ListNode* merge(ListNode* left, ListNode* right) {
        if (!left) return right;
        if (!right) return left;
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr = dummy;
        while (left && right) {
            if (left->val > right->val) {
                ptr->next = right;
                right = right->next;
            } else {
                ptr->next = left;
                left = left->next;
            }
            ptr = ptr->next;
        }
        ptr->next = left ? left : right;
        return dummy->next;
    }

    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr; 
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev) prev->next = nullptr; 
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* mid = findMid(head);
        ListNode* left = sortList(head); 
        ListNode* right = sortList(mid); 
        return merge(left, right);
    }
};
