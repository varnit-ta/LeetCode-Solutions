class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode *ptr1 = headA, *ptr2 = headB;

        while (ptr1 != ptr2) {
            ptr1 = (ptr1) ? ptr1->next : headB;
            ptr2 = (ptr2) ? ptr2->next : headA;
        }

        return ptr1; // ptr1 == ptr2 at the intersection node or both are nullptr
    }
};
