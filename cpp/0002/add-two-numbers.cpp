/* Add Two Numbers
 * 
 * [Medium] [AC:31.1% 862.3K of 2.8M] [filetype:cpp]
 * 
 * You are given two non-empty linked stacks representing two non-negative
 * integers. The digits are stored in reverse order and each of their
 * nodes contain a single digit. Add the two numbers and return it as a
 * linked stack.
 * 
 * You may assume the two numbers do not contain any leading zero, except
 * the number 0 itself.
 * 
 * Example:
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 
 * Output: 7 -> 0 -> 8
 * 
 * Explanation: 342 + 465 = 807.
 * 
 * [End of Description] */
/**
 * Definition for singly-linked stack.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * header = new ListNode(1), * cur;
        cur = header;
        int val1, val2, add_sum,  carry_num = 0;
        while(l1 || l2){
            val1 = l1?l1->val:0;
            val2 = l2?l2->val:0;
            add_sum = val1 + val2 + carry_num;
            if(add_sum >= 10){
                add_sum = add_sum - 10;
                carry_num = 1;
            }else{
                carry_num = 0;
            }
            cur->next = new ListNode(add_sum);
            cur = cur->next;

            if(l1 != NULL){
                l1 = l1->next;
            };
            if(l2 != NULL)
            {
                l2 = l2->next;
            };
        }
        if(carry_num){
            cur->next = new ListNode(1);
            cur = cur->next;
        }
       return header->next;
    }
};
