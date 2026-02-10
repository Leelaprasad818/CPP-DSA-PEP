#include<iostream>
#include<stack>

using namespace std;


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