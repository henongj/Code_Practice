#include<iostream>
#include<string>
#include<algorithm>

//https://leetcode.com/explore/learn/card/recursion-ii/470/divide-and-conquer/2874/

using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int min = 9999;
        int max = -1;
        return helper(root, min, max);
    }
    bool helper(TreeNode* root, int min, int max) {
        if (!root) return true;

        cout << root->val << "\n";

        helper(root->left, min, max);
        helper(root->right, min, max);
        return true;
    }
};

int main(void)
{
    Solution s = Solution();

	return 0;
}
//https://leetcode.com/explore/learn/card/recursion-ii/470/divide-and-conquer/
