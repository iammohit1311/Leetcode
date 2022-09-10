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
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp=head;
        int c=0;
        while(temp)
        {
         temp=temp->next;
            c++;
        }
        if(c == 1) return head = NULL;
        
        int k=c-n;
        
        if(k == 0)
        {
            //ListNode* temp = head;
            head = head->next;
            //temp->next = NULL;
            return head;
        }
        
        ListNode* tem=head;
        for(int i=1;i<k;i++)
        {
            tem=tem->next;
        }
        tem->next=tem->next->next;
        return head;
    }
        
       /* ListNode* start = new ListNode();
        
        start->next=head;
        ListNode* slow=start;
        ListNode* fast=start;
        
        for(int i=1; i<=n; i++)
        {
            fast=fast->next;
        }
        
        while(fast->next != NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        slow->next = slow->next->next;
        return start->next;
    } */
};