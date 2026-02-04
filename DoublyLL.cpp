#include<iostream>

using namespace std;


class Node{
    public:
    int data;
    Node* prev;
    Node* next;


    Node(int val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
    Node(){
        data = 0;
        prev = nullptr;
        next = nullptr;
    }
};

void insertNodeAtKthPosDLL(Node* &head,int val,int k){
    Node* n = new Node(val);

    Node* temp = head;
    int i=1;

    while(i<k-1){
        temp = temp->next;
        i++;
    }

    Node* nxt = temp->next;
    temp->next = n;
    n->prev = temp;
    n->next = nxt;
    nxt->prev = n;
}

void insertNodeAtHeadDLL(Node* &head,int val){
    Node* n = new Node(val);

    if(head == nullptr){
        head = n;
        return;
    }

    n->next = head;
    head->prev = n;
    head = n;
}

void insertNodeDLL(Node* &head,int val){
    Node* n = new Node(val);

    if(head == nullptr){
        head = n;
        return;
    }

    Node* temp = head;

    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp;

}


void printDLL(Node* head){
    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){

    int n;
    cout<<"ENTER SIZE OF ARR: "<<endl;
    cin>>n;

    vector<int> arr;
    cout<<"ENTER ARR VALS : "<<endl;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    Node* head = new Node(arr[0]);

    for(int i=1;i<n;i++){
        insertNodeDLL(head,arr[i]);
    }

    printDLL(head);

    insertNodeAtKthPosDLL(head,11,3);
    cout<<"After insertion at kth pos :"<<endl;

    printDLL(head);

}