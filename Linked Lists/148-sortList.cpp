/*  148. Sort List (merge sort)
    Sort a linked list in O(n log n) time using constant space complexity.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {

        if(!head || !head->next)
            return head;

        ListNode *slow= head, *fast= head;

        while(fast && fast->next && fast->next->next){
            fast= fast->next->next;
            slow= slow->next;
        }   //slow is now the head of second half of the list

        fast= slow;
        slow= slow->next;
        fast->next= NULL; 
        head= sortList(head);
        slow= sortList(slow);
        
        return sortedMerge(head, slow); 
    }
    
    ListNode* sortedMerge(ListNode* p, ListNode* q){

    ListNode *dummy=new ListNode(0),*ans=dummy; //created a dummy node. ans points to dummy node
    
        while(p!=NULL && q!=NULL){
            if(p->val < q->val){
                ans->next = p;
                p = p->next;
            }
            else{
                ans->next=q;
                q=q->next;
            }
            ans=ans->next;
        }
        
        if(p!=NULL)
            ans->next=p;
        if(q!=NULL)
            ans->next=q;
            
        ans=dummy->next; //set ans to the head of the list
        delete dummy;
        
        return ans;
    }
};