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
        stack<ListNode*> s1, s2;
        while(l1) {
            s1.push(l1);
            l1 = l1->next;
        }
        while(l2) {
            s2.push(l2);
            l2 = l2->next;
        }
        
        int sum = 0;
        ListNode* res = new ListNode(0);
        while(!s1.empty() || !s2.empty()) {
            if(!s1.empty()) {
                sum += s1.top()->val;
                s1.pop();
            }
            if(!s2.empty()) {
                sum += s2.top()->val;
                s2.pop();
            }
            res->val = sum % 10;
            ListNode* head = new ListNode(sum / 10);
            head->next = res;
            res = head;
            sum /= 10;
        }
        
        if(res->val == 0) {
            res = res->next;
        }
        
        return res;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = getLength(l1);
        int len2 = getLength(l2);
        int diff = abs(len1 - len2);
        if(len1 < len2) {
            swap(l1, l2);
        }
        
        ListNode* res = new ListNode(0);
        ListNode* curr = res;
        // from right to left,  the first one that val is not 9
        ListNode* right = res;
        // curr and right are both on res list.
        
        while(diff > 0) {
            curr->next = new ListNode(l1->val);
            if(l1->val != 9) {
                right = curr->next;
            }
            l1 = l1->next;
            curr = curr->next;
            diff--;
        }
        
        while(l1) {
            int val = l1->val + l2->val;
            if(val > 9) {
                val = val % 10;
                right->val++;
                while(right->next) {
                    right->next->val = 0;
                    right = right->next;
                }
            }
            
            curr->next = new ListNode(val);
            if(val != 9) {
                right = curr->next;
            }
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if(res->val == 0) {
            res = res->next;
        }
        
        return res;
    }
    
    int getLength(ListNode* l) {
        int len = 0;
        while(l) {
            len++;
            l = l->next;
        }
        return len;
    }
};