class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0); 
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Move fast ahead by n + 1 steps to maintain the gap
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the target node
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;  // Free memory (important in C++)

        return dummy.next;
    }
};

