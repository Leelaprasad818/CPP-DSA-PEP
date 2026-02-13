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


void insertInTree(Node* &root,int data){
    Node* n = new Node(data);
    if(root == nullptr){
        root = n;
        return;
    }

    Node* temp = root;
    if(temp->left == nullptr){
        temp->left = n;
        return;
    }
    if(temp->right == nullptr){
        temp->right = n;
        return;
    }
    insertInTree(temp->left,data);
    insertInTree(temp->right,data);

}

int countNodes(Node* root){
    if(root==nullptr) return 0;
    int x = countNodes(root->left);
    int y = countNodes(root->right);
    return x + y + 1;
    // mistake in this code check once
}

int countLeafNodes(Node* root){
    if(root==nullptr) return 0;
    if(root->left == nullptr && root->right == nullptr) return 1;
    int x = countLeafNodes(root->left);
    int y = countLeafNodes(root->right);
    return x + y + 1;
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
    cout<<"Preorder Traversal: "<<endl;
    preorder(root);
    cout<<"Post Order traversal : "<<endl;
    postorder(root);
    int count = countNodes(root);
    cout << "Total no.of Nodes: " << count;
    return 0;
}