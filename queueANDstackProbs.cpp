

/*
https://leetcode.com/problems/gas-station/description/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int bal = 0;
        int tot = 0;
        int curr = 0;
        int st = 0;

        for(int i=0;i<n;i++){
            bal = gas[i]-cost[i];
            tot += bal;
            curr += bal;

            if(curr < 0){
                st = i + 1;
                curr = 0;

            }
        }



        //if tot is -ve , no sol for that case
        if(tot < 0){
            return -1;
        }
        return st;
    }
};
*/

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

/*
https://leetcode.com/problems/implement-stack-using-queues/
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        int topVal = q1.front();
        q1.pop();
        return topVal;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};


 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 
*/


/*
https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1
class Solution {
  public:
  //11 12 13 14 15 16 17 18 19 20
    void rearrangeQueue(queue<int> &q) {
        // code here
        stack<int> st;
        int halfSize = q.size()/2;
        
        //push half ele into the stack
        //queue : 16 17 18 19 20 and stack : 15 14 13 12 11
        
        for(int i=0;i<halfSize ;i++){
            st.push(q.front());
            q.pop();
        }
        //enqueue back the stack elements
        //queue : 16 17 18 20 14 14 13 12 11
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        //dequeue the first half elememnts of queue and enqueue them back
        //queue : 15 14 13 12 11 16 17 18 19 20
        
        for(int i=0;i<halfSize ;i++){
            q.push(q.front());
            q.pop();
        }
        
        //again push the first half elements in stack 
        //queue : 16 17 18 19 20 stack:11 12 13 14 15
        
        
        for(int i=0;i<halfSize ; i++){
            st.push(q.front());
            q.pop();
        }
        
        
        //interleave the elements of queue and stack
        //queue : 11 16 12 17 13 18 14 19 15 20
        while(!st.empty()){
            q.push(st.top());
            st.pop();
            q.push(q.front());
            q.pop();
        }
        
    }
};
*/