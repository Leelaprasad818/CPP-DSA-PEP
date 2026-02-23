#include<iostream>
#include<queue>

using namespace std;


/*
priority queue is a special type of queue where elements are accessed on basis of priority , not the insertion order

by defalut it has highest element priority

internally 

*/


/*
https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1
class Solution {
  public:
    
    int count(Node* root){
        if(root == nullptr) return 0;
        return 1 + count(root->left) + count(root->right);
    }
    
    bool isCBT(Node* root,int idx,int count){
        if(root == nullptr) return true;
        
        if(idx >= count) return false;
        else{
            bool left = isCBT(root->left,2*idx+1,count);
            bool right = isCBT(root->right,2*idx+2,count);
            
            return (left && right);
        }
    }
    
    bool isMaxHeap(Node* root){
        if(root->left == nullptr && root->right == nullptr) return true;
        
        if(root->right == nullptr) return (root->data > root->left->data);
        else{
            bool left = isMaxHeap(root->left);
            bool right = isMaxHeap(root->right);
            
            return((left && right ) &&root->data > root->left->data && root->data > root->right->data);     
        }
    }
  
    bool isHeap(Node* tree) {
        // code here
        int idx = 0;
        int totCount = count(tree);
        if(isCBT(tree,idx,totCount) && isMaxHeap(tree)){
            return true;
        }
        return false;
    }
};
*/


/*
https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;

        for(int i : nums){
            m[i]++;
        }


        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(auto i : m){
            pq.push({i.second,i.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
*/

/*
https://leetcode.com/problems/find-k-closest-elements/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;

        priority_queue<pair<int,int>> heap;

        for(int i : arr){
            int d = abs(i-x);
            heap.push({d,i});
            if(heap.size() > k){
                heap.pop();
            }
        }


        while(!heap.empty()){
            ans.push_back(heap.top().second);
            heap.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
*/

/*
vector<vector<int>> diagonalWaveCollector(vector<vector<int>> &grid) {
    
    int m = grid.size();
    int n = grid[0].size();
    
    vector<vector<int>> result;
    
    for(int sum = 0; sum <= m + n - 2; sum++){
        vector<int> diagonal;
        
        for(int i = 0; i < m; i++){
            int j = sum - i;
            
            if(j >= 0 && j < n){
                diagonal.push_back(grid[i][j]);
            }
        }
        
        result.push_back(diagonal);
    }
    
    return result;
}
*/

/*
https://www.geeksforgeeks.org/problems/k-largest-elements4206/1
class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        priority_queue<int,vector<int> , greater<int>> heap;
        
        for(int i : arr){
            heap.push(i);
            if(heap.size()> k){
                heap.pop();
            }
        }
        
        vector<int> ans;
        
        while(!heap.empty()){
            ans.push_back(heap.top());
            heap.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
*/


/*
https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        priority_queue<int,vector<int>, greater<int>> minHeap;
        
        
        int n = arr.size();
        for(int i=0;i<k+1;i++){
            minHeap.push(arr[i]);
        }
        
        int idx = 0;
        
        for(int i=k+1;i<n;i++){
            arr[idx++] = minHeap.top();
            minHeap.pop();
            minHeap.push(arr[i]);
        }
        while(!minHeap.empty()){
            arr[idx++] = minHeap.top();
            minHeap.pop();
        }
        
    
    }
};
*/

/*
https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minHeap;


        for(int i: nums){
            minHeap.push(i);

            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};
*/



int main(){

    //max heap
    priority_queue<int> pq_max;
    //min heap
    priority_queue<int,vector<int>,greater<int>> pq_min;

    pq_max.push(10);
    pq_max.push(5);
    pq_max.push(20);


    cout<<pq_max.size()<<endl;

    while(!pq_max.empty()){
        cout<<pq_max.top()<<" ";
        pq_max.pop();
    }
    cout<<pq_max.empty()<<endl;

}
