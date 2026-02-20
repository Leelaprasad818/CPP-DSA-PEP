#include<iostream>
#include<queue>

using namespace std;


/*
priority queue is a special type of queue where elements are accessed on basis of priority , not the insertion order

by defalut it has highest element priority

internally 

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
