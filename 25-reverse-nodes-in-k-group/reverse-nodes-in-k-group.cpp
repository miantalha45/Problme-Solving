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
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;

        ListNode* leftEnd = head;
        ListNode* rightEnd = head;

        for (int i = 1; i < k; i++) {
            if (rightEnd->next != nullptr) {
                rightEnd = rightEnd->next;
            } else {
                return head;
            }
        }
        ListNode* afterRight = rightEnd->next;
        rightEnd->next = nullptr;

        cur->next = reverse(leftEnd);
        leftEnd->next = reverseKGroup(afterRight, k);
        return dummy->next;
    }

private:
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};