/*
Leetcode Link : https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/
*/

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        int n = 0;
        ListNode* curr = head;
        while(curr != NULL)
        {
            curr = curr->next;
            n++;
        }
        if(n==1)
            return head;

        ListNode* prev = NULL;
        curr = head;
        while(curr != NULL)
        {
            if(prev!=NULL)
            {
                int gcd = __gcd(prev->val , curr->val);
                ListNode* newNode = new ListNode(gcd);
                prev->next = newNode;
                newNode->next = curr;
               
            }
            prev = curr;
            curr = curr->next;
        }  

        return head;
    }
};