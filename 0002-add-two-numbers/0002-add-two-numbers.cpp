class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead = new ListNode(0);
        ListNode *ptr1 = dummyHead, *ptr2 = l1, *ptr3 = l2;
        int carry = 0;
        
        while (ptr2 || ptr3 || carry) {
            int val = carry;
            
            if (ptr2) {
                val += ptr2->val;
                ptr2 = ptr2->next;
            }
            
            if (ptr3) {
                val += ptr3->val;
                ptr3 = ptr3->next;
            }
            
            carry = val / 10;
            ptr1->next = new ListNode(val % 10);
            ptr1 = ptr1->next;
        }

        return dummyHead->next;
    }
};
