/*
Leetcode Link : https://leetcode.com/problems/spiral-matrix-iv/description/
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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>mat(m,vector<int>(n,-1));
        vector<int>vec;
        while(head!=NULL)
        {
            vec.push_back(head->val);
            head=head->next;
        }
        int right = n-1, left = 0;
        int top = 0,down = m-1;

        int dir = 0;
        int size = vec.size();
        int idx = 0;
        while(left <= right && top<=down)
        {
            if(dir==0)// left to right
            {
                for(int i=left;i<=right;i++)
                {
                    if(idx<size)
                    {
                         mat[top][i] = vec[idx++];
                    }
                    else
                        break;
                   
                }
                top++;
            }
            else if(dir==1) // top to down
            {
                for(int i=top;i<=down;i++)
                {
                    if(idx<size)
                        mat[i][right] = vec[idx++];
                    else
                        break;
                }
                right--;
            }
            else if(dir==2) /// right to left
            {
                for(int i=right;i>=left;i--)
                {
                    if(idx<size)
                        mat[down][i]=vec[idx++];
                    else
                        break;
                }
                down--;
            }
            else if(dir==3) // down to top
            {
                for(int i=down;i>=top;i--)
                {
                    if(idx<size)
                        mat[i][left]=vec[idx++];
                    else
                        break;
                }
                left++;
            }

            dir = (dir+1)%4;
        }

        return mat;
        
    }
};