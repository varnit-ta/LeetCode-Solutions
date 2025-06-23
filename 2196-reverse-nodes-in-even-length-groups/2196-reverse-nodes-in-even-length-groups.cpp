class Solution {
public:
    void reverse(ListNode* prevStart, ListNode* last){
        ListNode *prev = last, *curr = prevStart->next, *next;

        while (curr != last){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        prevStart->next = prev;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* ptr = dummy;
        int group = 1;

        while (ptr->next){
            ListNode* groupStartPrev = ptr;
            ListNode* groupEnd = ptr->next;

            int count = 0;
            for (int i = 0; i < group && groupEnd; ++i){
                count++;
                groupEnd = groupEnd->next;
            }

            if (count % 2 == 0){
                reverse(groupStartPrev, groupEnd);
                ptr = groupStartPrev;
            }
            
            for (int i = 0; i < count; ++i)
                ptr = ptr->next;

            group++;
        }

        return dummy->next;
    }
};
