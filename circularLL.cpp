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

void deleteAtBeginCLL(Node* &head){
    if(head == nullptr) return;

    if(head->next == head){
        Node* del = head;
        head = nullptr;
        delete del;
        return;
    }
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    Node* del = head;
    temp->next = head->next;
    head = del->next;
    delete del;
}

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
    if(head == nullptr){
        cout<<"LIST IS EMPTY";
        return;
    }
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

void deleteLastNodeCLL(Node* &head){
    if(head == nullptr) return;
    if(head->next == head) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;

    while(temp->next->next != head){
        temp = temp->next;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
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
    cout<<endl<<"AFTER INSERTION"<<endl;
    printCLL(head);

    deleteLastNodeCLL(head);
    cout<<endl<<"AFTER DELETION OF LAST NODE"<<endl;
    printCLL(head);

    deleteAtBeginCLL(head);
    cout<<endl<<"AFTER DELETION OF Head NODE"<<endl;
    printCLL(head);

}