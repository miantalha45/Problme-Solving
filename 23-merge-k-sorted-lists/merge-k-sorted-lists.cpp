/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptrptr) {}
 *     ListNode(int x) : val(x), next(nullptrptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        while (lists.size() > 1) {
            vector<ListNode*> newLists;

            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
                newLists.push_back(merge(l1, l2));
            }

            lists = newLists;
        }

        return lists[0];
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        // l1 = [2], l2 = [1,3]
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        }
        // l1 = [2], l2 = [1,3]
        else {
            // l1 = [2], l2 = [1->]
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};