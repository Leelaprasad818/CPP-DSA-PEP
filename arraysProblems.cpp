https://www.geeksforgeeks.org/problems/reverse-an-array/1
class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int i = 0;
        int j = arr.size()-1;
        while(i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
};


https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1
class Solution {
  public:
    bool isSorted(vector<int>& arr) {
        // code here
        int i = 0;
        int j = 1;
        while(j<=arr.size()-1){
            if(arr[i]>arr[j]){
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};


https://leetcode.com/problems/running-sum-of-1d-array/submissions/1894074550/
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            nums[i] += nums[i-1]; 
        }

        return nums;

    }
};


//Time complex:

1.O(1) -> constant time: time taken doesnt depend on input size 

2.O(n) -> Linear time: the time grows directly proportional to input size;

3.O(logn) -> Logarithmic time: time grows Logarithmically as input size inc, often seen in alogs divide input int half like binary search

4.O(nlogn) -> Linearithmic time: a mix of linear and Logarithmic , quick and merge sort

5.O(n^2) -> Quadratic time: time grows proportional to n 


https://www.geeksforgeeks.org/problems/reverse-array-in-groups0255/1
class Solution {
  public:
    void reverse(vector<int>& arr,int i,int j){
        while(i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        
    }
    void reverseInGroups(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k>n){
            reverse(arr,0,n-1);
            return;
        }
        int i=0;
        while(i+k-1 < n){
            reverse(arr,i,i+k-1);
            i = i+k;
        }
        reverse(arr,i,n-1);
    }
};



https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int curr = nums[0];
        for(int i = 1; i < nums.size(); i++){
            curr = max(nums[i], curr + nums[i]);
            maxSum = max(maxSum, curr);
        }

        return maxSum;
    }
};


https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
class Solution {
  public:

    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        int firstSum = 0;
        int i;
        for(i=0;i<k;i++){
            firstSum += arr[i];
        }
        int max_sum = firstSum;
        i=k;
        while(i<n){
            firstSum += arr[i]-arr[i-k];
            i++;
            max_sum = max(max_sum,firstSum);
            
        }
        return max_sum;
    }
};


https://leetcode.com/problems/remove-duplicates-from-sorted-array/i

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*
        set<int> s(nums.begin(),nums.end());
        nums.assign(s.begin(),s.end());
        return nums.size();
        */
        int i=0;
        int j=1;
        for(int j=1;j<nums.size();j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};



https://leetcode.com/problems/palindrome-linked-list/submissions/1907710769/

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
    void reverse(ListNode* &head){
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp != nullptr){
            ListNode* nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }

        head = prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head;
        ListNode* temp = head;
        while(second!=nullptr && second->next != nullptr){
            first = first->next;
            second = second->next->next;
        }

        reverse(first);

        while(first != nullptr){
            if(temp->val != first->val){
                return false;
            }
            temp = temp->next;
            first = first->next;
        }

        return true;

    }
};


https://leetcode.com/problems/middle-of-the-linked-list/

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
    ListNode* middleNode(ListNode* head) {
        ListNode* first = head;
        ListNode* last = head;

        while(last != nullptr && last->next != nullptr){
            first = first->next;
            last = last->next->next;
        }

        return first;
    }
};


