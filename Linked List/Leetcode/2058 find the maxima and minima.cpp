/*

Leetcode Link : https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/?envType=daily-question&envId=2024-07-05
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp = head->next;
        int curr = 1;
        ListNode* prev = head;
        int first_pos = -1;
        int temp_pos = -1;
        int prev_pos = -1;
        int min = INT_MAX ;
        while(temp->next != NULL)
        {
            if(prev->val < temp->val && temp->next->val < temp->val)
            {
                if(first_pos == -1)
                    first_pos = curr;
                else
                {
                    if(temp_pos != -1)
                    {
                        prev_pos = temp_pos;
                        temp_pos = curr;
                        if(temp_pos - prev_pos < min)
                            min = temp_pos - prev_pos;
                    }
                    else
                        {
                            temp_pos = curr;

                            if(temp_pos - first_pos < min)
                                min = temp_pos - first_pos;
                        }
                }
            }
            
            else if(prev->val > temp->val && temp->next->val > temp->val)
            {
               
                if(first_pos == -1)
                    first_pos = curr;
                else
                {
                    if(temp_pos != -1)
                    {
                        prev_pos = temp_pos;
                        temp_pos = curr;
                        if(temp_pos - prev_pos < min)
                            min = temp_pos - prev_pos;
                    }
                    else
                        {
                            temp_pos = curr;

                            if(temp_pos - first_pos < min)
                                min = temp_pos - first_pos;
                        }
                }

            }
           
            prev = temp;
            temp = temp->next;
            curr++;

        }
        
        int max = -1;
        if(first_pos != -1 && temp_pos != -1)
            max = temp_pos - first_pos;

        if(min == INT_MAX)
        {
            if(max != -1)
                min = max;
            else
                min = -1;
        }
        return {min,max};

        
    }
   
};