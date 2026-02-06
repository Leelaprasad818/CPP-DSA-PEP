#include<iostream>

using namespace std;






/* Node is defined as
https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* temp = head;
        Node* zeros = new Node(0);
        Node* ones = new Node(0);
        Node* twos = new Node(0);
        
        Node* z = zeros;
        Node* o = ones;
        Node* t = twos;
        
        
        while(temp != nullptr){
            if(temp->data == 0){
                z->next = temp;
                z = z->next;
            }else if(temp->data == 1){
                o->next = temp;
                o = o->next;
            }else{
                t->next = temp;
                t = t->next;
            }
            temp = temp->next;
        }
        
        z->next = ones->next;
        o->next = twos->next;
        
        return zeros->next;
        
    }
};
*/



/**
https://leetcode.com/problems/partition-list/description/?envType=problem-list-v2&envId=linked-list
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* dummyR = new ListNode(0);
        ListNode* dummyL = new ListNode(0);
        ListNode* right = dummyR;
        ListNode* left = dummyL;

        ListNode* temp = head;

        while(temp != nullptr){
            ListNode* nxt = temp->next;
            temp->next = nullptr;
            if(temp->val < x){
                left->next = temp;
                left = left->next;
            }
            else{
                right->next = temp;
                right = right->next;
            }
            temp = nxt;
        }
        left->next = dummyR->next;
        return dummyL->next;
    }
};
*/


/**
https://leetcode.com/problems/intersection-of-two-linked-lists/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return nullptr;

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        
        while(temp1 != temp2){
            temp1 = (temp1 == nullptr) ? headB : temp1->next;
            temp2 = (temp2 == nullptr) ? headA : temp2->next;
        }

        return temp1;
    }
};
*/

/**
https://leetcode.com/problems/linked-list-cycle-ii/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast){
                slow = head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
*/


/**
https://leetcode.com/problems/linked-list-cycle/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        }

        return false;
    }
};
*/

/**
https://leetcode.com/problems/palindrome-linked-list/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

class Solution {
public:
    void reverse(ListNode* &head){
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp != nullptr){
            ListNode* nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }

        head = prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head;
        ListNode* temp = head;
        while(second!=nullptr && second->next != nullptr){
            first = first->next;
            second = second->next->next;
        }

        reverse(first);

        while(first != nullptr){
            if(temp->val != first->val){
                return false;
            }
            temp = temp->next;
            first = first->next;
        }

        return true;

    }
};
*/

/**
https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head){
        if(head == nullptr) return head;
        if(head->next == nullptr) return head;
        ListNode* temp = head;
        while(head->next != nullptr){
            if(head->val == head->next->val){
                ListNode* n = head->next;
                head->next = n->next;
                delete n;
            }else{
            head = head->next;
            }
        }
        return temp;
    }
};




/*
https://www.geeksforgeeks.org/problems/insert-in-a-sorted-list/1
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    // Should return head of the modified linked list
    Node* sortedInsert(Node* head, int key) {
        // Code here
        Node* temp = head;
        Node* n = new Node(key);
        if(head->data > n->data){
            n->next = head;
            head = n;
            return head;
        }
        
        while(temp->next != nullptr){
            if(temp->next->data >= n->data){
                n->next = temp->next;
                temp->next = n;
                return head;
            }
            temp = temp->next;
        }
        if(temp->data <= n->data && temp->next == nullptr){
            temp->next = n;
        }
        
        return head;
    }
};


*/

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