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
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode* current = head;
        while(current != NULL)
        {
            st.push(current->val);
            current = current->next;
        }

        ListNode* p = head;
        int maxSum = 0;
        while(p != NULL)
        {
            int sum = p->val + st.top();
            st.pop();
            maxSum = max(sum, maxSum);
            p = p->next;
        }
        return maxSum;
    }
};