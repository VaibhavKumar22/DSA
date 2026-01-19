class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int,int> mp;
        for(int x : nums) mp[x] = 1;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = dummy;

        while(curr->next) {
            if(mp[curr->next->val]) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};

