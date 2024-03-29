/***                                                *
 * 1. Iteration                                     *                                  
 * Time complexity : O(m + n)                       *
 * Space complexity : O(1)                        ***/


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* head = new ListNode(0);
        ListNode* ret = head;
        
        while(l1 && l2) {
            
            if(l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            }
            else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        
        head->next = l1 ? l1 : l2;
        
        return ret->next;
    }
};

/***                                                *
 * 2. Recursion                                     *                                  
 * Time complexity : O(m + n)                       *
 * Space complexity : O(m + n)                    ***/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(!l1) {
            return l2;
        }
        if(!l2) {
            return l1;
        }
        
        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};