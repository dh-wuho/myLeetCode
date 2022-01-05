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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* curr = head;
        while(curr && curr->next) {
            if(curr->val == curr->next->val) {
                ListNode* tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;
            }
            else {
                curr = curr->next;   
            }    
        }
        
        return head;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        head->next = deleteDuplicates(head->next);
        
        if(head->val == head->next->val) {
            ListNode* tmp = head->next;
            delete head;
            return tmp;
        }
        return head;
    }
};