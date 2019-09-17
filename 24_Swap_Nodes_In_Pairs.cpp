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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = dummy->next;
        
        while(curr && curr->next) {
            prev->next = curr->next;
            prev = prev->next;
            curr->next = prev->next;
            prev->next = curr;
            prev = curr;
            curr = curr->next;
        }
        
        return dummy->next;
    }
};


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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* res = head->next;
        head->next = swapPairs(res->next);
        res->next = head;
        return res;
    }
};