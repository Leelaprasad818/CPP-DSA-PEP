#include<iostream>
using namespace std;



//HEAP:
/*
1.it is a complete Binary Tree, which follows heap order property

complete binary tree(CBT) : 1. all levels are comletely filled except the last level , it is filled from
                             left to right

heap order property :1.MAX HEAP -> every parent node is greater than or equal to its children       
                     2.MIN HEAP -> every parent is smaller than or equal to its children the smallest element
                      is always at top

**IMP note: heap is not BST 

1.for any node a)(0 - idx  based) : left child -> 2*i + 1
                                    right child -> 2*i + 2
                                    parent -> (i-1)/2
                b)(1 - idx based) : left child -> 2*i
                                    right child -> 2*i + 1
                                    parent -> i/2


*/


class MaxHeap{
    public:
    vector<int> heap;

    void bubbleUp(int i){

        while(i > 0){
            int parent = (i-1)/2;

            if(heap[i] > parent){
                swap(heap[i],heap[parent]);
                i = parent;
            }else{
                break;
            }
        }
    }

    void bubbleDown(int idx){
        vector<int> heap;
        int i = 0,n = heap.size();
        while(i<n){
            int left = 2*i+1;
            int right = 2*i+2;
            int large = i;
            if(left < n && heap[left] > heap[large]){
                large = left;
            }
            if(right < n && heap[right] > heap[large]){
                large = right;
            }
            if(large != 1){
                swap(heap[i],heap[large]);
                i = large;
            }
            else{
                break;
            }

        }

    }

    void heapify(vector<int> &arr , int n , int i){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;

        if(left<n && arr[left] > arr[largest]){
            largest = left;
        }
        if(right < n && arr[right] > arr[largest]){
            largest = right;
        }

        if(largest != i){
            swap(arr[i],arr[largest]);
            heapify(arr,n,largest);
        }

    }


    void buildMAXheap(vector<int> &arr,int n){
        for(int i=n/2-1;i>=0;i--){
            heapify(arr,n,i);
        }
    }
/*
    void deletion(int idx){
        vector<int> heap;
        int i=0,n=heap.size();
        while(){

        }
    }
        */

    void insertInHeap(int val){
        heap.push_back(val);
        bubbleUp(heap.size()-1);
    }



};






int main(){
    vector<int> arr = {10,3,5,13,2,8,15};

    int n = arr.size();

    cout<<"ORIGINAL ARR : "<<endl;
    for(int i : arr){
        cout<<i<<" ";
    }

    cout<<endl;

    buildMAXheap(arr,n);
     cout<<"MAX HEAP : "<<endl;
    for(int i : arr){
        cout<<i<<" ";
    }

}