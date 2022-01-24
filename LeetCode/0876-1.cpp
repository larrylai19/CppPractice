class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int length = 0;
        auto ans = head;
        for(auto it = head; it != nullptr; it = it->next, ++length);
        for(int i = 0; i < length / 2; ++i, ans = ans->next);
        return ans;
    }
};