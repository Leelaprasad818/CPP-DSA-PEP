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

void insertNodeAtKthPos(Node* &head,int val,int k){
    Node* temp = head;
    Node* n = new Node(val);

    int i = 1;

    while(i<k){
        temp = temp->next;
        i++;
    }
    if(temp->next == nullptr){
        temp->next = n;
        return;
    }
    n->next = temp->next;
    temp->next = n;
}

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

void insertAthead(Node* &head,int val){
    Node* n = new Node(val);

    if(head == nullptr) head = n;

    n->next = head;
    head = n;
}
/*
void deleteNode(Node* head,int data){

}*/

int sumOfNodeLL(Node* head){
    int sum = 0;

    while(head != nullptr){
        sum += head->data;
        head = head->next;
    }
    return sum;

}

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
    insertNode(head,6);
    insertNode(head,12);

    printLL(head);
    insertNodeAtKthPos(head,5,2);
    cout<<" ";
    printLL(head);
}