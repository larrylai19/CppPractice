class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        auto tortoise = head, hare = head;
        while(hare && hare->next)
        {
            hare = hare->next->next;
            tortoise = tortoise->next;
        }
        return tortoise;
    }
};