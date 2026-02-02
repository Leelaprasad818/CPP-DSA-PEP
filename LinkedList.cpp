#include<iostream>

using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = nullptr;
    }
    Node(){
        data = 0;
        next = nullptr;
    }
};

void insertNode(Node* &head,int data){
    Node* n = new Node(data);
    if(head == nullptr){
        head = n;
        return;
    }
    Node* temp = head;

    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = n;
}
/*
void deleteNode(Node* head,int data){

}

int sumOfNodeLL(Node* head){


}*/

void printLL(Node* head){
    Node* temp = head;

    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){

    Node* head = new Node(1);
    insertNode(head,4);
    insertNode(head,3);

    printLL(head);

}