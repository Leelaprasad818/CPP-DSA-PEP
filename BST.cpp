/*
A binary search tree is a special type of tree where 
#every node has at most two children 

#for every node
    all values in the LST are smaller 
    all values in RST are greater 

#both LST and RST are also BST

#inorder traversal of a BST is always sorted

*/



/*
https://leetcode.com/problems/validate-binary-search-tree/
class Solution {
public:
    bool check(TreeNode* root,long long min,long long  max){
        if(!root) return true;

        if(root->val <=min || root->val >= max) return false;
        return check(root->left,min,root->val) && check(root->right,root->val,max);
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        return check(root,LONG_MIN,LONG_MAX);
    }
};
*/


/*
https://leetcode.com/problems/kth-smallest-element-in-a-bst/
class Solution {
public:
    void inorder(TreeNode* root,vector<int> &inord){
        if(!root) return;

        inorder(root->left,inord);
        inord.push_back(root->val);
        inorder(root->right,inord);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;

        vector<int> inord;
        inorder(root,inord);

        return inord[k-1];
    }
};
*/


/*

https://leetcode.com/problems/number-of-islands/
#include <bits/stdc++.h>
using namespace std;

class solution{
public:
    void helper(int i,int j,vector<vector<int>> grid,vector<vector<int>> &visited){
        if(visited[i][j] == 1) return;
        
        visited[i][j] = 1;
    
        if(grid[i][j] == 1){
            if(i-1 >=0 && visited[i-1][j] != 1){
                helper(i-1,j,grid,visited);
            }
            if(i+1 < grid.size() && visited[i+1][j] != 1){
                helper(i+1,j,grid,visited);
            }
            if(j-1 >=0 && visited[i][j-1] != 1){
                helper(i,j-1,grid,visited);
            }
            if(j+1 < grid[0].size() && visited[i][j+1] != 1){
                helper(i,j+1,grid,visited);
            }
        }
    }
    
    int numOfIslands(vector<vector<int>>& grid){
        // Write your code here...
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && visited[i][j] == 0){
                    count++;
                    helper(i,j,grid,visited);
                }
            }
        }
        return count;
    }
};
*/


/*
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
    TreeNode* helper(vector<int> nums,int l,int h){
        if(l>h) return nullptr;
        int m =  (h+l)/2;
        TreeNode* root = new TreeNode(nums[m]);

        root->left = helper(nums,l,m-1);
        root->right = helper(nums,m+1,h);

        return root;

    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return helper(nums,0,nums.size()-1);
    }
};
*/


/*
https://www.geeksforgeeks.org/problems/minimum-element-in-bst/0
class Solution {
  public:
    int leftLeaf(Node* root){
        if(root->left == nullptr) return root->data;
        leftLeaf(root->left);
    }
    int minValue(Node* root) {
        // code here
        if(!root) return 0;
        return leftLeaf(root);
        
    }
};
*/

/*
https://leetcode.com/problems/insert-into-a-binary-search-tree/
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);

        if(val<root->val){
            root->left = insertIntoBST(root->left,val);

        }else{
            root->right = insertIntoBST(root->right,val);
        }

        return root;
    }
};
*/


/*
https://leetcode.com/problems/search-in-a-binary-search-tree/
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return root;

        if(root->val == val) return root;

        if(root->val > val) return searchBST(root->left,val);
        else return searchBST(root->right,val);
    }
};
*/

/*
https://leetcode.com/problems/range-sum-of-bst/
class Solution {
public:
    void makeSum(int l,int h,TreeNode* root,int &sum){
        if(root == nullptr) return;
        if(root->val <= h && root->val >= l){
            sum += root->val;
        }
        makeSum(l,h,root->right,sum);

        makeSum(l,h,root->left,sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        makeSum(low,high,root,sum);
        return sum;
    }
};
*/