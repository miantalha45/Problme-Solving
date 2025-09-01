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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == nullptr)    return head;
        ListNode* slow = head;
        ListNode* fast = head->next;

        ListNode* res = fast;
        ListNode* prev = nullptr;

        while(fast != nullptr) {
            ListNode* temp = fast->next;
            fast->next = slow;
            if(prev != nullptr)
                prev->next = fast;
            slow->next = temp;
            prev = slow;
            slow = slow->next;
            fast = slow != nullptr ? slow->next : nullptr;
        }

        return res;
    }
};