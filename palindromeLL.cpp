class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        
        ListNode *slow=head, *fast=head;
        
        while(fast->next!=NULL && fast->next->next != NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        slow->next = revList(slow->next);
        slow=slow->next;
        
        while(slow != NULL)
        {
            if(head->val != slow->val) return false;
            slow=slow->next;
            head=head->next;
        }
        return true;
    }
    
    ListNode* revList(ListNode* head)
    {
        ListNode *pre=NULL, *next=NULL;
        while(head!=NULL)
        {
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
    
};
