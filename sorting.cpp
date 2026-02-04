#include<iostream>

using namespace std;


void bubbleSort(vector<int> &arr,int n){

}

void selectionSort(vector<int> &arr,int n){

}

void insertionSort(vector<int> &arr,int n){

}

void quickSort(vector<int> &arr,int n){

}

void mergeSort(vector<int> &arr,int n){

}


bool isSorted(vector<int> arr,int n){
    for(int i=0;i<n;i++){
        if(arr[i]>arr[i+1]) return false;
    }
    return true;
}


int main(){

    int n;
    cout<<"Enter len of arr :"
    cin>>n;
    cin>>
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    if(isSorted(arr,n)){
        cout<<"Array is Sorted ASC";
    }else{
        bool sort;
        cin>>"Do sort :">>sort;
        if(sort){
            int option;
            cout<<"SELECT OPTION : 1:bubble 2:selection 3:insertion 4:quick 5:merge sorting methos : ">>option;
        }
    }

}