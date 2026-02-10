#include<iostream>
#include<stack>

using namespace std;



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

    cout<<endl;
    string str = "Hello, how are you?";
    cout<<"reversed string words of string : "<<endl;
    reverseStringWords(str);
    cout<<endl;
    cout<<"reversed string : "<<endl;
    reverseString(str);


}