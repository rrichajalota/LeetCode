/* (Q-86) Partition List
	Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

	You should preserve the original relative order of the nodes in each of the two partitions.

	For example,
	Given 1->4->3->2->5->2 and x = 3,
	return 1->2->2->4->3->5.
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
    ListNode* partition(ListNode* head, int x) {
        if (!head)
            return head;
        ListNode *temp= head, *prev= NULL, *next, *smallhead= NULL, *small= NULL, *largehead= NULL;
        while(temp){
            next= temp->next;
            if(temp->val < x){
                if(smallhead==NULL){
                    smallhead= small= temp;
                    small->next= NULL;
                    if(prev){
                        prev->next=next;
                    }
                    temp= next;
                }
                else{
                    small->next= temp;
                    small= temp;
                    if(prev){
                        prev->next= next;
                    }
                    temp= next;
                }
            }
            else{
                if(largehead == NULL)
                    largehead= temp;
                prev= temp;
                temp= next;
            }
        }
        if (small){
            small->next= largehead;
            head= smallhead;
        }
        return head;
    }
};