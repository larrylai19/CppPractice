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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, firstNode = 1;
        auto res = l1, curr = l1;
        while(l1 || l2 || carry != 0)
        {
            if(l1)
                carry += l1->val, l1 = l1->next;
            if(l2)
                carry += l2->val, l2 = l2->next;
            auto newNode = new ListNode(carry % 10);
            if(firstNode)
                res = curr = newNode, --firstNode;
            else
                curr->next = newNode, curr = curr->next;
            carry /= 10;
        }
        return res;
    }
};