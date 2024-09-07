/*
Leetcode link : https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int>ans;
        stack<Node*>st;
        if(root == NULL)
            return ans;
        st.push(root);
        while(!st.empty())
        {
            Node* temp = st.top();
            ans.push_back(temp->val);
            st.pop();
            for(auto it : temp->children)
            {
                st.push(it);
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};