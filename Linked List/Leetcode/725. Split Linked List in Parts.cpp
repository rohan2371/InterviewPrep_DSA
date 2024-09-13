/*
Leetcode Link : https://leetcode.com/problems/split-linked-list-in-parts/description/
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
        ListNode* currNode = head;
        while(currNode !=  NULL)
        {
            currNode = currNode->next;
            size++;
        }

        int eachBucket = size/k;
        int remNodes = size%k;

        vector<ListNode*>ans(k,NULL);
        currNode = head;
        ListNode* prev = NULL;
        for(int i=0;i<k;i++)
        {
            ans[i] = currNode;
            for(int j=1;j<=eachBucket+(remNodes> 0 ? 1:0);j++)
            {
                prev = currNode;
                currNode = currNode->next;
            }
            if(prev != NULL)
                prev->next = NULL;
            remNodes--;
        }

        return ans;
    }
};