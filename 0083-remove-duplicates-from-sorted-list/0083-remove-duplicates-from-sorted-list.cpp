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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == NULL)
        {
            return head;
        }
        
        ListNode* trav = head;
        ListNode* temp = trav->next;
        
        while(temp != NULL)
        {
            if(trav->val != temp->val)
            {
                trav->next = temp;
                trav = temp;
                temp = trav->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        trav->next = temp;
        return head;
        
    }
};