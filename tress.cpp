#include<iostream>
using namespace std;


/*
tree-> it is a non linear , hierarchical data structure consisting of nodes connected by edges 
binary tree-> when every node has at most 2 children 

terminologies :
1.leaf : a node with no children 
2.internal : node which is not a leaf 
3.siblings : the children of same parent
4.path : len of path is 1 less than the number of nodes in the path
5.ancestors and decendents : if there is a path from node a to node b then a is called an ancestors of b and b is called a decendent of a 
6.subtree : any node of a tree , with all of its decendents is a subtree 
7.level : the level of the node refers to its distance from the root , the root of the tree has generally level 0
8.height : the max level of tree determines its height , the height of the node in a tree is the length of the longest path from that node to the leaf
9.depth : the depth of the node is the number of nodea along the path from the root to that node


properties :
1.if h = ht of the binary tree , then 
    a. max num of leaves 2^h
    b. max nodes = 2^(h+1)-1

2.if a bin tree containes m nodes at LV1 , it contains at most 2m nodes at level l + 1
3.since a bin tree can contain atmost one node at LV0(root), it can contain 2^l nodes  at lv l
4.total num of edges in a full bin tree with n nodes is n-1

types :
 1.full bin tree : a tree of ht h has all its leaves at LV h , means all non leaf nodes of a FBT have two children , and the leaf nodes have no children
 2.complete bin tree : all LV are filled , the nodes must fill from left to right

*/



/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;

        if(root == p || root == q) return root;
        TreeNode* l = lowestCommonAncestor(root->left,p,q);
        TreeNode* r = lowestCommonAncestor(root->right,p,q);

        if(l && r){
            return root;
        }else if(l != nullptr) return l;
        return r;
    }
};
*/


/*
https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int> res;
        if(root == nullptr) return res;
        
        map<int,int> m;
        
        queue<pair<Node* , int>> q;
        
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int> frontVal = q.front();
            q.pop();
            
            Node* node = frontVal.first;
            int hd = frontVal.second;
            
            
            if(m.find(hd) == m.end()){
                m[hd] = node->data;
            }
            
            if(node->left != nullptr) q.push(make_pair(node->left,hd-1));
            if(node->right != nullptr) q.push(make_pair(node->right,hd+1));
            
            
        }
        for(auto i : m){
            res.push_back(i.second);
        }
        
        return res;
    }
};
*/

/*
https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
class Solution {
public:

    void traverseLeft(Node* root, vector<int>& ans){
        if(root == nullptr || (root->left == nullptr && root->right == nullptr))
            return;

        ans.push_back(root->data);

        if(root->left)
            traverseLeft(root->left, ans);
        else
            traverseLeft(root->right, ans);
    }

    void traverseLeaf(Node* root, vector<int>& ans){
        if(root == nullptr)
            return;

        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(root->data);
            return;
        }

        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }

    void traverseRight(Node* root, vector<int>& ans){
        if(root == nullptr || (root->left == nullptr && root->right == nullptr))
            return;

        if(root->right)
            traverseRight(root->right, ans);
        else
            traverseRight(root->left, ans);

        ans.push_back(root->data);  // add after recursion
    }

    vector<int> boundaryTraversal(Node *root) {

        vector<int> ans;

        if(root == nullptr)
            return ans;

        ans.push_back(root->data);

        traverseLeft(root->left, ans);

        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);

        traverseRight(root->right, ans);

        return ans;
    }
};

*/

/*
https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        if(root == nullptr) return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> eles;
            for(int i=0;i<size;i++){
                Node* front = q.front();
                q.pop();
                
                eles.push_back(front->data);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            ans.push_back(eles[0]);
        }
        
        return ans;
    }
};
*/

/*
https://leetcode.com/problems/binary-tree-right-side-view/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        if(root == nullptr) return res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> eles;

            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();

                eles.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            int s = eles.size();
            res.push_back(eles[s-1]);
        }
        return res;
    }
};
*/



/*
https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sums;
        if(root == nullptr) return 0;

        queue<TreeNode*> q;

        q.push(root);


        while(!q.empty()){
            int size = q.size();
            long long sum = 0;
            
            for(int i=0;i<size;i++){
                TreeNode* frontNode = q.front();
                q.pop();
                sum += frontNode->val;
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }

            sums.push_back(sum);
        }
        sort(sums.begin(),sums.end());
        int n = sums.size();
        if(n>=k) return sums[sums.size()-k];
        return -1;

    }
};

*/


/*
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;


        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        while(!q.empty()){
            vector<int> els;
            int size = q.size();


            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                els.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(count == 0){
                res.push_back(els);
                count = 1;
            }else{
                reverse(els.begin(),els.end());
                res.push_back(els);
                count = 0;
            }

        }
        return res;

    }
};
*/

/*
https://leetcode.com/problems/binary-tree-level-order-traversal/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;


        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> lvE;
            for(int i=0;i<size;i++){
                TreeNode* frontNode = q.front();
                q.pop();

                lvE.push_back(frontNode->val);
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }

            res.push_back(lvE);
        }

        return res;
    }
};
*/



/*
https://leetcode.com/problems/invert-binary-tree/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        TreeNode* lft = invertTree(root->left);
        TreeNode* rgt = invertTree(root->right);
        root->left = rgt;
        root->right = lft;
        return root;
    }
};
*/



/*
https://leetcode.com/problems/same-tree/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        
        bool right = isSameTree(p->right,q->right);
        bool left = isSameTree(p->left,q->left);

        return left && right;
        
    }
};
*/



/*
https://leetcode.com/problems/sum-of-left-leaves/
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr ) return 0;
        int sum = 0;

        if(root->left && root->left->left == nullptr && root->left->right == nullptr) {
            sum += root->left->val;
        }

        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);
        return sum;
    }
};
*/


/*
https://leetcode.com/problems/maximum-depth-of-binary-tree/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
*/


/*
https://www.geeksforgeeks.org/problems/height-of-binary-tree/1
class Solution {
  public:
    int height(Node* root) {
        // code here
        if(root == nullptr) return -1;
        
        int leftHt = height(root->left);
        int rightHt = height(root->right);
        
        return max(leftHt,rightHt)+1;
    }
};
*/


/**
https://leetcode.com/problems/binary-tree-inorder-traversal/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };

class Solution {
public:
    void helper(TreeNode* root,vector<int> &ans){
        if(root == nullptr) return;

        helper(root->left,ans);
        ans.push_back(root->val);
        helper(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root,ans);

        return ans;
    }
};
*/



class Node{
    public:

    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};


int sumOfAllNodes(Node* root){
    if(root == nullptr) return 0;
    return sumOfAllNodes(root->left) + sumOfAllNodes(root->right) + root->data;
}

void insertInTree(Node* &root, int data){
    Node* newNode = new Node(data);

    if(root == nullptr){
        root = newNode;
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp->left == nullptr){
            temp->left = newNode;
            return;
        } else {
            q.push(temp->left);
        }

        if(temp->right == nullptr){
            temp->right = newNode;
            return;
        } else {
            q.push(temp->right);
        }
    }
}


int countNodes(Node* root){
    if(root==nullptr) return 0;
    int x = countNodes(root->left);
    int y = countNodes(root->right);
    return x + y + 1;
}

int countLeafNodes(Node* root){
    if(root==nullptr) return 0;
    if(root->left == nullptr && root->right == nullptr) return 1;
    int x = countLeafNodes(root->left);
    int y = countLeafNodes(root->right);
    return x + y;
}

void inorder(Node* root){
    if(root == nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == nullptr){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}



int main(){
    cout<<"ENTER size of ARR"<<endl;
    int n;
    cin>> n;
    int arr[n];
    cout<<"ENTER values of ARR"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node* root = new Node(arr[0]);
    for(int i=1;i<n;i++){
        insertInTree(root,arr[i]);
    }
    cout<<"INORDER TRAVERSAL : "<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Preorder Traversal: "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Post Order traversal : "<<endl;
    postorder(root);
    cout<<endl;
    int count = countNodes(root);
    cout << "Total no.of Nodes: " << count;
    cout<<endl<<"Sum of Nodes : "<<endl;
    cout<<sumOfAllNodes(root)<<endl;



}