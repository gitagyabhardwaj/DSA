/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:

    TreeNode* tobst(vector<int>& num, int left, int right){
        if(left>right){
            return nullptr;
        }

        int mid = (left+right)/2;
        TreeNode* root = new TreeNode(num[mid]);

        root->left = tobst(num, left, mid-1);
        root->right = tobst(num, mid+1, right);

        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return tobst(nums, 0, nums.size()-1);
    }
};