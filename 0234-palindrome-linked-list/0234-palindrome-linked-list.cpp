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
    bool isPalindrome(ListNode* head) {
        vector<int>ans;

        ListNode* temp = head;

        while(temp != NULL) {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        
        int flag = 0;
        int size = ans.size();

        int i = 0, j = size-1;

        while(i<j) {
            if(ans[i] != ans[j]) 
              flag = 1;
            
            i++;
            j--;
        }
        if(flag == 1) return false;

        return true;
    }
};