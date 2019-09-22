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
        ListNode* flag_l1 = l1;
        ListNode* flag_l2 = l2;
        ListNode* result = new ListNode(0);
        ListNode* flag_res = result;
        int carry=0;
        while(flag_l1 || flag_l2){
            int num1 = flag_l1 ? (*flag_l1).val : 0;
            int num2 = flag_l2 ? (*flag_l2).val : 0;
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            int val = sum % 10;
            cout << val << " ";
            (*flag_res).val = val;
            flag_l1 = flag_l1 ? (*flag_l1).next : NULL;
            flag_l2 = flag_l2 ? (*flag_l2).next : NULL;
            if(flag_l1 || flag_l2){  
                 (*flag_res).next = new ListNode(0);
                flag_res = (*flag_res).next;
            }
        }
        if(carry){
            (*flag_res).next = new ListNode(0);
            flag_res = (*flag_res).next;
            (*flag_res).val = carry;
        }
        return result; 
    }
};
