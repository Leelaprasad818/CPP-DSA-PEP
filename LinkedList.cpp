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

void deleteNode(Node* &head,int pos){
    if(head == nullptr) return;
    Node* temp = head;

    if(pos == 1){
        head = head->next;
        delete temp;
        return;
    }
    int n=1;

    while(temp != nullptr){
        if(n==pos-1){
            break;
        }
        temp = temp->next;
        n++;
    }

    Node* del = temp->next;
    temp->next = del->next;

    delete del;
}

int countEvenNodesLL(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp!=nullptr){
        if((temp->data)%2 == 0){
            count++;
        }
        temp = temp->next;
    }
    return count;
}

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

bool checkEleLLRecursion(Node* head,int target){
    if(head == nullptr) return false;
    if(head->data == target) return true;
    return checkEleLLRecursion(head->next,target);
}

int main(){

    Node* head = new Node(1);
    insertNode(head,4);
    insertNode(head,3);
    insertNode(head,6);
    insertNode(head,12);
    cout<<"AFTER INSERTION LL: "<<endl;
    printLL(head);
    cout<<endl;
    insertNodeAtKthPos(head,5,2);
    cout<<"AFTER INSERTION AT KTH POS LL: "<<endl;
    printLL(head);
    cout<<endl;
    cout<<"AFTER DELETION AT POS LL: "<<endl;
    deleteNode(head,3);
    printLL(head);

    cout<<endl;
    int n;
    cout<<"ENTER SIZE OF ARR : "<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"ENTER DATA OF ARR : "<<endl;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
}
    Node* userHead = new Node(arr[0]);
    for(int i=1;i<n;i++){
        insertNode(userHead,arr[i]);
    }
    cout<<"VALUES OF USERHEAD : "<<endl;
    printLL(userHead);

    cout<<endl<<"Count of even val Nodes in userhead : "<<endl;
    cout<<countEvenNodesLL(userHead);

    cout<<endl;
    cout<<"ENTER TARGET VALUE : "<<endl;

    int target;
    cin>>target;
    cout<<"IS ELEMENT FOUND : "<<endl;
    cout<<checkEleLLRecursion(userHead,target);
}