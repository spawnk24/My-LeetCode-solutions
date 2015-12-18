/*Add two Nums
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = NULL;
        ListNode *tmp = NULL;
        int vf = 0;
        int vs = 0;
        int ntmp = 0;
        int carry = 0;
        while(l1 || l2){
            vf = l1 ? l1->val : 0;
            vs = l2 ? l2->val : 0;
            ntmp = (vf + vs + carry) % 10;
            carry = (vf + vs + carry) / 10;
            if (tmp){
                tmp->next = new ListNode(ntmp);
                tmp = tmp->next;
            }
            else{
                res = new ListNode(ntmp);
                tmp = res;
            }
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        if (carry != 0)
            if (tmp){
                tmp->next = new ListNode(1);
                tmp = tmp->next;
            }
            else{
                res = new ListNode(1);
                tmp = res;
            }
        return res;
    }
};