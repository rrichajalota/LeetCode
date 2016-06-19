/*  LEETCODE QUESTION 203
    Remove all elements from a linked list of integers that have value val.

    Example
    Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
    Return: 1 --> 2 --> 3 --> 4 --> 5
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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return head;
        ListNode *temp= head, *prev=NULL;
        while(temp){
            if(temp->val==val){
                if (temp==head){
                    head= temp->next;
                    temp= head;
                }
                else{
                    prev->next= temp->next;
                    temp= temp->next;
                }
            }
            else{
                prev= temp;
                temp= temp->next;
            }
        }
        return head;
    }
};