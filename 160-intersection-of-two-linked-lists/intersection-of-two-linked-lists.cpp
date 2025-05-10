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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        int skipA = 0;
        int skipB = 0;
        while(l1 != NULL && l2 != NULL)
        {
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != NULL)
        {
            l1 = l1->next;
            skipA++;
        }

        while(l2 != NULL)
        {
            l2 = l2->next;
            skipB++;
        }
        
        l1 = headA;
        l2 = headB;

        if(skipA > 0)
        {
            for(int i = 0; i < skipA; i++)
            {
                l1 = l1->next;
            }
        }
        else{
            for(int i = 0; i < skipB; i++)
            {
                l2 = l2->next;
            }
        }

        while(l1 != NULL && l2 != NULL)
        {
            if(l1 == l2)
            {
                return l1;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        return NULL;
    }
};