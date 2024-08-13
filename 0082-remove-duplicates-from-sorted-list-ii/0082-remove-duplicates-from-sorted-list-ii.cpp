class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        ListNode dummy(0, head);
        ListNode* pb = &dummy; 
        ListNode* pa = head; 

        while (pa != nullptr) {
            bool isDuplicate = false;

            while (pa->next != nullptr && pa->val == pa->next->val) {
                pa = pa->next;
                isDuplicate = true;
            }

            if (isDuplicate) {
                pb->next = pa->next;
            } else {
                pb = pb->next;
            }

            pa = pa->next;
        }

        return dummy.next;
    }
};