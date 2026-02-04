#include<iostream>
#include<vector>

using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

void insertNodeAtHeadCLL(Node* &head,int val){
    Node* n = new Node(val);
    if(head == nullptr){
        head = n;
        head-> next = head;
        return;
    }
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
    head = n;

}


void printCLL(Node* head){
    Node* temp = head;

    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != head);
}

void insertNodeCLL(Node* &head,int val){
    Node* n = new Node(val);

    if(head == nullptr){
        head = n;
        head->next = head;
        return;
    }
    Node* temp = head;

    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;


}


int main(){
    int n;
    cout<<"ENTER SIZE OF ARR : "<<endl;
    cin>>n;


    vector<int> arr;
    cout<<"ENTER VALUES OF ARR : "<<endl;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    Node* head = nullptr;
    for(int i=0;i<n;i++){
        insertNodeCLL(head,arr[i]);
    }

    printCLL(head);



}