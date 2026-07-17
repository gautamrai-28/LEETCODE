/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 /*there would be total 3 steps
    1. Find the middle of list
    2. reverse first half or second half of the list
    3. compare both list if not equal return false else true
*/
class Solution {
public:
    //step 2 : reverse second half of the list
    ListNode* reverseList(ListNode* head) {

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr!=NULL) {
            ListNode* forwad = curr->next;

            curr->next = prev;

            prev = curr;
            curr = forwad;
        }
        
        head = prev;
        return head;
    }

    bool isPalindrome(ListNode* head) {

        // if(head == NULL || head->next == NULL)
        //    return true;

        //step 1: find midde of the list
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //step2
        ListNode* head2 = reverseList(slow);

        ListNode* curr1 = head;
        ListNode* curr2 = head2;

        //step 3: comapre both lists
        while(curr1 != NULL && curr2 != NULL) {

            if(curr1->val != curr2->val) 
              return false;
            
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return true;

    }
};