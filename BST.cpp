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
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        map<int,map<int,multiset<int>>> m;

        queue<pair<TreeNode* ,pair<int,int> > > q;

        q.push({root,{0,0}});

        while(!q.empty()){

            auto front = q.front();
            TreeNode* node = front.first;
            int pos1 = front.second.first;
            int pos2 = front.second.second;
            q.pop();

            m[pos1][pos2].insert(node->val);

            if(node->left) q.push({node->left,{pos1-1,pos2+1}});
            if(node->right) q.push({node->right,{pos1+1,pos2+1}});
        }

        for(auto &p : m){
            vector<int> column;
            for(auto &q : p.second){
                column.insert(column.end(), q.second.begin(), q.second.end());
            }
            res.push_back(column);
        }
        return res;
    }
};
*/


/*
https://leetcode.com/problems/delete-node-in-a-bst/
 //step1 : find the node to be deleted by comparisions 
 //step2:restructive its children while preserving BST order

 //there can be 3 cases for deleting a node
 //1.no children (leaf node ) this can be deleted directly 
 //2.one child - can replace the current node with its only child
 //3.two child - to maintain BST order, we need either 
class Solution {
public:
    TreeNode* minEle(TreeNode* node){
        while(node->left != nullptr){
            node = node->left;
        }
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;

        if(key < root->val){
            root->left = deleteNode(root->left,key);
        }else if(key > root->val){
            root->right = deleteNode(root->right,key);
        }else{
            //case 1 : node has no left child
            //replace node with its right child
            if(root->left == nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            //case 2 : node has no right child
            //replace node with its left child
            else if(root->right == nullptr){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            //case 3 : node has 2 childs
            //find inorder successor 
            TreeNode* temp = minEle(root->right);

            root->val = temp->val;


            root->right = deleteNode(root->right,temp->val);
        }
        return root;
    }
};*/

/*
https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1
class Solution {
  public:
    void inorder(Node* root,Node* &ans){
        if(!root) return;
        inorder(root->left,ans);
        Node* n = new Node(root->data);
        ans->right = n;
        ans = ans->right;
        inorder(root->right,ans);
    }
    Node *flattenBST(Node *root) {
        // code here
        if(!root) return root;
        Node* dumm = new Node(0);
        Node* ans = dumm;
        
        inorder(root,ans);
        
        return dumm->right;
    }
};
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