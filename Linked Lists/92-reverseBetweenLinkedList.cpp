/*	Leetcode Question- 92 Reverse Linked List
	Reverse a linked list from position m to n. Do it in-place and in one-pass.

	For example:
	Given 1->2->3->4->5->NULL, m = 2 and n = 4,

	return 1->4->3->2->5->NULL.

	Note:
	Given m, n satisfy the following condition:
	1 ≤ m ≤ n ≤ length of list.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head->next || n < m)
            return head;
            
        ListNode *first= head, *prev1= NULL;
        for(int i=1; i<m ; i++){
            prev1= first;
            first= first->next;
        }
        ListNode *second= first->next, *prev2= first, *secondnext;
        
        for(int i= 1; i<= n-m ; i++){
            secondnext= second->next;
            second->next= prev2;
            prev2= second;
            second= secondnext;
        }
        
        if(!prev1){
            head= prev2;
            first->next= second;
        }
        else{
            prev1->next= prev2;
            first->next= second;
        }
        return head;
    }
};