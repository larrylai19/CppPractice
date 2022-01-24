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
    void reorderList(ListNode* head) {
        if(!head) return;
        auto mid = findMid(head), l1 = head, l2 = mid->next;
        mid->next = nullptr;
        l2 = _reverse(l2);
        while(l1 && l2)
        {
            auto _next = l1->next;
            l1->next = l2;
            l2 = l2->next;
            l1->next->next = _next;
            l1 = _next;
        }
    }
private:
    ListNode* findMid(ListNode* head)
    {
        auto slow = head, fast = head;
        while(fast && fast->next) fast = fast->next->next, slow = slow->next;
        return slow;
    }
    
    ListNode* _reverse(ListNode* head)
    {
        ListNode* newhead = nullptr;
        while(head)
        {
            auto _next = head->next;
            head->next = newhead;
            newhead = head;
            head = _next;
        }
        return newhead;
    }
};