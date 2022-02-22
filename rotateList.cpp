class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        
        //compute length
        ListNode *cur=head;
        int len=1;
        while(cur->next && ++len)
            cur=cur->next;
        
        //Go till that node
        cur->next=head;
        k=k%len;
        k=len-k;
        
        while(k--) cur=cur->next;
        
        //Make this node head and break connection
        head=cur->next;
        cur->next=NULL;
        return head;
    }
};
