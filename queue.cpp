#include<iostream>

using namespace std;

/*
https://leetcode.com/problems/design-circular-queue/
class MyCircularQueue {
public:
    vector<int> data;
    int front,rear,size,count;
    MyCircularQueue(int k) {
        front = 0;
        rear = -1;
        count = 0;
        size = k;
        data.clear();
        data.resize(k);
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        rear = (rear+1)%size;
        data[rear] = value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        front = (front+1)%size;
        count--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return data[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return data[rear];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
};
*/




/*
https://www.geeksforgeeks.org/problems/queue-reversal/1
class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        if(q.empty()) return;
        int temp = q.front();
        q.pop();
        
        reverseQueue(q);
        q.push(temp);
    }
};
*/


class myQueue{
    public:
    int* arr;
    int front;
    int rear;
    int size;

    myQueue(int size){
        this->size = size;
        arr = new int(size);
        front = -1;
        rear = -1;
    }

    void enqueue(int val){
        if(rear == size-1){
            cout<<"Queue overflow"<<endl; 
            return ;
        }
        if(front == -1){
            front = 0;
        }
        rear++;
        arr[rear] = val;
    }

    void dequeue(){
        if(front == -1 || front>rear){
            cout<<"Queue is empty"<<endl;
            return;
        }
        front++;
    }

    int getFront{
        if(front == -1 || front > rear){
            cout<<"queue is empty"<<end;
            return -1;
        }
        return arr[front];
    }

}



int main(){

}