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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = 0;
        while(temp!=NULL) {
            len++;
            temp = temp->next;
        }

        if(n==len) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
        int count = len - n;
        temp = head;

        while(temp != NULL) {
            count -= 1;

            if(count == 0) {
                ListNode* delNode = temp->next;
                temp->next = temp->next->next;
                delete delNode;
                break;
            }

            temp = temp->next;
        }

        return head;
    }
};