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
        return Add(l1, l2, 0);
    }

    ListNode* Add(ListNode* l1, ListNode* l2, int carry) {
        if (l1 == nullptr && l2 == nullptr && carry == 0)
            return nullptr;

        int val1 = (l1 != nullptr) ? l1->val : 0;
        int val2 = (l2 != nullptr) ? l2->val : 0;

        int sum = val1 + val2 + carry;
        int newDigit = sum % 10;
        int newCarry = sum / 10;

        ListNode* node = new ListNode(newDigit);
        node->next = Add((l1 != nullptr) ? l1->next : nullptr,
                         (l2 != nullptr) ? l2->next : nullptr, newCarry);

        return node;
    }
};