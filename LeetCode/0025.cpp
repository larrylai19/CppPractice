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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || !head || !head->next) return head;
        
        vector<ListNode*> v;
        auto curr = head;
        auto newHead = head;
        auto lastNode = head;
        bool firstGroup = false;
        
        while (curr) {
            v.push_back(curr);
            curr = curr->next;

            if (v.size() == k) {
                auto tmp = curr;
                
                for (int i = v.size() - 1; i > 0; --i) {
                    v[i]->next = v[i - 1];
                }

                v[0]->next = tmp;
                
                if (!firstGroup) newHead = v.back();
                else lastNode->next = v.back();

                lastNode = v[0];
                
                firstGroup = true;
                
                v.clear();
            }
        }
        
        return newHead;
    }
};