/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> data;

    void captureData(ListNode* root){
        ListNode *ptr = root;

        while (ptr != NULL){
            data.push_back(ptr->val);
            ptr = ptr->next;
        }
    }

    vector<int> reverseKGroup(vector<int>& group, int k) {
        if (group.size() < k) {
            return group;
        }
        reverse(group.begin(), group.begin() + k);
        return group;
    }

    ListNode* createLinkedList(const vector<int>& data) {
        ListNode* root = nullptr;
        ListNode* current = nullptr;
        for (int val : data) {
            if (root == nullptr) {
                root = new ListNode(val);
                current = root;
            } else {
                current->next = new ListNode(val);
                current = current->next;
            }
        }
        return root;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        captureData(head);
        int n = data.size();
        for (int i = 0; i < n; i += k) {
            if (i + k <= n) {
                vector<int> group(data.begin() + i, data.begin() + i + k);
                group = reverseKGroup(group, k);
                data.erase(data.begin() + i, data.begin() + i + k);
                data.insert(data.begin() + i, group.begin(), group.end());
            }
        }
        return createLinkedList(data);
    }
};