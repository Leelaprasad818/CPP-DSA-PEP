#include<iostream>
#include<stack>
#include<cmath>
using namespace std;


vector<int> nextSmallerElement(vector<int> arr){
    int n = arr.size();
    stack<int> st;
    vector<int> nse(n);


    for(int i=0;i<n;i++){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        if(st.empty()){
            nse[i] = -1;
        }else{
            nse[i] = st.top();
        }
        st.push(arr[i]);
    }

    return nse;
}



vector<int> nextGreaterElement(vector<int>&arr){
    int n = arr.size();
    stack<int> st;
    vector<int> nge(n);

    for(int i=n-1;i>=0;i--){
        //remove all elements smaller than or equal to current element 
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(st.empty()){
            nge[i] = -1;
        }else{
            nge[i] = st.top();
        }
        st.push(arr[i]);
    }
    return nge;
}


/*
https://leetcode.com/problems/next-greater-element-i/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater;
        stack<int> s;

        for(int num : nums2){
            while(!s.empty() && num>s.top()){
                next_greater[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }


        while (!s.empty()) {
            next_greater[s.top()] = -1;
            s.pop();
        }

        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(next_greater[num]);
        }
        return ans;
    }
};
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
https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1
// User function Template for C++

class Solution {
  public:
    stack<int> insertAtBottom(stack<int> st, int x) {
        if(st.empty()){
            st.push(x);
            return st;
        }
        
        int topValue = st.top();
        st.pop();
        
        st = insertAtBottom(st,x);
        st.push(topValue);
        
        return st;
    }
};
*/


/*
https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                }
                char top = st.top();
                st.pop();
                if (ch == ')' && top != '(') return false;
                if (ch == ']' && top != '[') return false;
                if (ch == '}' && top != '{') return false;
            }
        }
        return st.empty();
    }
};
*/

/*
https://www.naukri.com/code360/problems/delete-middle-element-from-stack_985246?leftPanelTabValue=SUBMISSION
delete middle node from stack
#include <bits/stdc++.h> 

void deleteFromStack(stack<int>&inputStack,int count,int size){
   if(inputStack.empty() || count == size/2){
      inputStack.pop();
      return;
   }

   int temp = inputStack.top();
   inputStack.pop();
   deleteFromStack(inputStack,count + 1,size);
   inputStack.push(temp);
}

void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   int count = 0;
   deleteFromStack(inputStack,count,N);
   
}
*/


int prefixEval(string s){
    stack<int> st;

    for(int i = s.size()-1;i>=0;i--){
        if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i] == '^'){
            int opt1 = st.top();
            st.pop();
            int opt2 = st.top();
            st.pop();
            int ans;
            if(s[i] == '+') ans = opt1 + opt2;
            else if(s[i] == '/') ans = opt1 / opt2;
            else if(s[i] == '*') ans = opt1 * opt2;
            else if(s[i] == '^') ans = pow(opt1 , opt2);
            else ans = opt1 - opt2;
            st.push(ans);
        }else{
            st.push(s[i]-'0');
        }
    }
    return st.top();
}

int postfixEval(string s){
    stack<int> st;

    for(int i = 0;i<s.size();i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i] == '^'){
            int opt1 = st.top();
            st.pop();
            int opt2 = st.top();
            st.pop();
            int ans;
            if(s[i] == '+') ans = opt1 + opt2;
            else if(s[i] == '/') ans = opt1 / opt2;
            else if(s[i] == '*') ans = opt1 * opt2;
            else if(s[i] == '^') ans = pow(opt1 , opt2);
            else ans = opt1 - opt2;
            st.push(ans);
        }else{
            st.push(s[i]-'0');
        }
    }
    return st.top();
}




void reverseStringWords(string str){
    stack<string> st;

    for(int i=0;i<str.length();i++){
        string word = "";
        while(str[i] != ' ' && i < str.length()){
            word += str[i];
            i++;
        }
        st.push(word);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
}

void reverseString(string str){
    stack<char> st;

    for(int i=0;i<str.length();i++){
        st.push(str[i]);
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }cout<<endl;
}


/*
class myStack{
    void pop(){
        if(top == NULL){
            Node* temp = top;

        }
    }
}*/


int main(){

    /*
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    
    cout<<st.top()<<end;
    st.pop()
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
    */

    /*
    cout<<endl;
    string str = "Hello, how are you?";
    cout<<"reversed string words of string : "<<endl;
    reverseStringWords(str);
    cout<<endl;
    cout<<"reversed string : "<<endl;
    reverseString(str);
    */

    /*
    string s;
    cout<<"Give prefix Expression for evaluation: "<<endl;
    cin>> s;
    int result = prefixEval(s);
    cout<<"Result of prefix Evaluation: "<<result;
    */

    vector<int> arr = {4,5,2,10,8};
    vector<int> nge = nextGreaterElement(arr);
    vector<int> nse = nextSmallerElement(arr);
    for(int i: nse){
        cout<<i<<" ";
    }


}