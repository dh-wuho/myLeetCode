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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        int length = 0;
        ListNode* curr = head;
        ListNode* newHead;
        while(curr->next) {
            curr = curr->next;
            length++;
        }
        length++;
        curr->next = head;
        for(int i = 0; i < length - k % length; i++) {
            curr = curr->next;
        }
        newHead = curr->next;
        curr->next = NULL;
        
        return newHead;
    }
};