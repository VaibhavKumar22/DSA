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
    int getDecimalValue(ListNode* head) {
        ListNode* temp=head;
        int i=0;
        while(temp!=nullptr){
            // a+=to_string(temp->val);
            i++;
            temp=temp->next;
        };
        int res=0;
        temp=head;
        while(temp!=nullptr){
            if(temp->val==1)
            res+=pow(2,i-1);
            temp=temp->next;
            i--;
        };
        
       
        return res;
        
    }
};
