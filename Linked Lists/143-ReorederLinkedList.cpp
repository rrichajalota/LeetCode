// Question 143 - Reorder List
/*	Given a singly linked list L: L0→L1→…→Ln-1→Ln,
	reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

	You must do this in-place without altering the nodes' values.

	For example,
	Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode* head) {
        if(!head || !head->next){
            return ;
        }
        ListNode *slow= head, *fast= head;
        while(fast!=NULL && fast->next != NULL && fast->next->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;
        }
        ListNode* midhead= slow->next, *temp= midhead,*prev=NULL, *next;
        slow->next= NULL;
        while(temp->next){
            next= temp->next;
            temp->next= prev;
            prev= temp;
            temp= next;
        }
        temp->next= prev;
        midhead= temp;
        ListNode* first= head, *second= midhead, *nextfirst;
        while(first && second){
            midhead= second->next;
            nextfirst= first->next;
            second->next= first->next;
            first->next= second;
            first= nextfirst;
            second= midhead;
        }
    }
};