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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int l = 1;

        ListNode* p = head;
        ListNode* dummy1 = new ListNode(0);
        ListNode* curr = dummy1;
        ListNode* dummy2 = new ListNode(0);
        ListNode* leftEnd = dummy2;

        while (p != nullptr && l <= right) {
            if(l >= left) {
                curr->next = p;
                curr = curr->next;
            } else {
                leftEnd->next = p;
                leftEnd = leftEnd->next;
            }
            p = p->next;
            l++;
        }

        ListNode* temp = curr->next;
        curr->next = nullptr;

        leftEnd->next = reverse(dummy1->next);

        while(leftEnd->next != nullptr) {
            leftEnd = leftEnd->next;
        }

        leftEnd->next = temp;
        return dummy2->next;
    }


private:
    ListNode* reverse(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        
        return newHead;
    }
};