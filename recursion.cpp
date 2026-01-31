#include<iostream>

using namespace std;


bool isArrSorted(int arr[],int size){
    if(size == 0 || size == 1) return true;
    if(arr[0] > arr[1]) return false;
    return isArrSorted(arr+1,size-1);
}
void findEle(int arr[],int s,int k,bool &isFound){
    if(s==0) return ;
    if(arr[s] == k){
        isFound = true;
         return;
    }
    findEle(arr,s-1,k,isFound);
}

int sumOfArr(int arr[],int idx){
    if(idx == 0) return arr[0];
    return arr[idx] + sumOfArr(arr,idx-1);
}
int main(){
    int k=0;
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout<<isArrSorted(arr,10);

    cout<<sumOfArr(arr,9);
    int k = 11;
    bool isFound = false;
    findEle(arr,9,k,isFound);
    cout<<isFound;
    cout<<"HI"<<endl;
}