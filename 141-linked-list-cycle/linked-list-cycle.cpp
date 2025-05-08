/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        unordered_set<ListNode*> set;
        ListNode* p = head;

        while(p != NULL)
        {
            if(set.find(p) != set.end())
            {
                return true;
            }
            else{
                set.insert(p);
            }
            p = p->next;
        }

        return false;
    }
};