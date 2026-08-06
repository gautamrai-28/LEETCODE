class Solution {
public:
    typedef pair<int, ListNode*> P;
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<P, vector<P>, greater<P>> pq;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL)
                pq.push({lists[i]->val, lists[i]});
        }

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (!pq.empty()) {
            auto p = pq.top();

            temp->next = p.second;
            pq.pop();

            if (p.second->next)
                pq.push({p.second->next->val, p.second->next});

            temp = temp->next;
        }

        return dummyNode->next;
    }
};