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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* l, ListNode* r) { return l->val > r->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        auto head = new ListNode(), tail = head;
        for(auto& ptr : lists) if(ptr) pq.push(ptr);
        while(!pq.empty())
        {
            tail->next = pq.top(), tail = tail->next, pq.pop();
            if(tail->next) pq.push(tail->next);
        }
        return head->next;
    }
};