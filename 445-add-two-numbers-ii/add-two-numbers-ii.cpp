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
        l1 = reverse(l1);
        l2 = reverse(l2);

        
        ListNode* res = Add(l1, l2, 0);
        return reverse(res);
    }

    ListNode* Add(ListNode* l1, ListNode* l2, int carry) {
        if(l1 == nullptr && l2 == nullptr && carry == 0) {
            return NULL;
        }
        int val1 = l1 == nullptr ? 0 : l1->val;
        int val2 = l2 == nullptr ? 0 : l2->val;

        int sum = val1 + val2 + carry;
        int newDigit = sum % 10;
        int newCarry = sum / 10;

        ListNode* node = new ListNode(newDigit);
        node->next = Add((l1 != NULL) ? l1->next : NULL,
                         (l2 != NULL) ? l2->next : NULL, newCarry);

        return node;
    }
    
    ListNode* reverse(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        
        return newHead;
    }
};