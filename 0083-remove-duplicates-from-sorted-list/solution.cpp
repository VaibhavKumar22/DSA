class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;

        while (temp != nullptr && temp->next != nullptr) {
            if (temp->val == temp->next->val) {
                temp->next = temp->next->next;  // Remove duplicate
            } else {
                temp = temp->next;  // Move forward only if no duplicate
            }
        }

        return head;
    }
};

