#include<iostream>

using namespace std;

void printArrWave(int arr[][4],int r,int c){
    for(int i=0;i<c;i++){
        if(i%2 == 0){
            for(int j=0;j<r;j++){
                cout<<arr[j][i]<<" ";
            }
        }else{
            for(int j=r-1;j>=0;j--){
                cout<<arr[j][i]<<" ";
            }
        }
        cout<<endl;
    }
}

void printArrSpiral(int arr[][4],int r,int c){
    int topR = 0;
    int botR = r - 1;
    int lftC = 0;
    int rgtC = c - 1;


    while(topR <= botR && lftC <= rgtC){
        //print top row
        for(int i= lftC;i<=rgtC;i++){
            cout<<arr[topR][i]<<" ";
        }
        topR++;
        //print right col

        for(int i=topR;i<=botR;i++){
            cout<<arr[i][rgtC]<<" ";
        }
        rgtC--;
        //print bottom row

        for(int i=rgtC;i>=lftC;i--){
            cout<<arr[botR][i]<<" ";
        }

        botR--;

        //print left col

        for(int i=botR;i>lftC;i--){
            cout<<arr[i][lftC]<<" ";
        }
        lftC++;
    }
}

void maxRowSumInx(int arr[][4],int r,int c){
    int maxSum = 0;
    int idx = 0;
    for(int i=0;i<r;i++){
        int sum = 0;
        for(int j=0;j<c;j++){
            sum += arr[i][j];
        }
        if(sum > maxSum){
            idx = i;
            maxSum = sum;
        }
    }

    cout<<"MAX ROW SUM :" <<maxSum<<endl;
    cout<<"ROW IDX :"<<idx<<endl;
}

void maxColSumInx(int arr[][4],int r,int c){
    int maxSum = 0;
    int idx = 0;
    for(int i=0;i<c;i++){
        int sum = 0;
        for(int j=0;j<r;j++){
            sum += arr[j][i];
        }
        if(sum > maxSum){
            idx = i;
            maxSum = sum;
        }
    }

    cout<<"MAX Col SUM :" <<maxSum<<endl;
    cout<<"Col IDX :"<<idx<<endl;
}


void rowSum(int arr[][4],int r,int c){

    for(int i=0;i<r;i++){
        int sum = 0;
        for(int j=0;j<c;j++){
            sum += arr[i][j];
        }
        cout<<sum<<endl;
    }
}


int main(){

    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    rowSum(arr,3,4);
    maxRowSumInx(arr,3,4);
    maxColSumInx(arr,3,4);
    int arr1[4][4] = {{1,7,14,6},{11,15,5,10},{2,4,16,3},{9,13,8,12}};
    printArrWave(arr1,4,4);
    printArrSpiral(arr1,4,4);
}