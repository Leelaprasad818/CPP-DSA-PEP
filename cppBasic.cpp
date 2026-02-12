#include <iostream>
using namespace std;


void mergesort(vector<int>&nums1,int m,vector<int>&nums2,int n){
    int i=m-1,j=n-1,k=m+n-1;
    while(i>=0 && j>=0){
        if(nums1[i] > nums2[j]){
            nums1[k] = nums1[i];
            k--;
            i--;
        }else{
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
    while(i>=0)
        nums1[k--] = nums1[i--];
    while(j>=0)
        nums1[k--] = nums2[j--];
}
int sub(int a,int b)
{
        return a - b;
}
class Student{
    public:
    string name;
    string section;
    int rollNo;

    Student(string name,string section,int rollNo){
        this->name = name;
        this->section = section;
        this->rollNo = rollNo;
    }
};

void selectionSort(vector<int> &arr){
    int n = arr.size();
    int k = 0;

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                if(arr[k]>arr[j]){
                    k=j;
                }
            }
            swap(arr[i],arr[k]);
        }
    }
}
void bubbleSort(vector<int> &arr){
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int sum(int arr[5]){
    int sum = 0;
    for(int i=0;i<5;i++){
        sum += arr[i];
    }
    return sum;
}

int linearSearch(int arr[10],int k){
    for(int i=0;i<10;i++){
        if(arr[i] == k){
            if(k>5) return 2*k;
            else return k/2;
        }
    }
    return -1;
}

void printEvnNumsBetNandM(int n,int m){
    if(n>m) return;
    if(n%2 == 0) cout<<n<<" ";
    printEvnNumsBetNandM(n+1,m);
}

int XpowerN(int x,int n){
    if(n==0) return 1;
    return x*XpowerN(x,n-1);
}

int main()
{
    //int a = 5;
    //cout<<++a;
    //operators
    //arithmatic : + - / % *
    //cout << a + b << endl;
    //a++ , ++a 
    //cout<<a++ + ++b << endl;
    
    //relational : < > <= >= ==
    //cout<<a==b;
    
    //logical : && ||
    
    /*int age = 25;
    bool hasId = true;
    if(age>=20 && hasId){
        
    }*/
    
    /*int interest;s
    cin>> interest;
    if(interest>50) cout<<"PAY THE TAX!!!";
    else cout<<"NO TAX!";*/

    //cout<<sub(5,7);

    /*int a = 6;
    int *ptr = &a;

    cout<<a<<endl;
    cout<<ptr<<endl;
    cout<<*ptr<<endl; //dereferencing ptr
    cout<<&a<<endl;*/

    //class

    // Student s1 = Student("Raju","K23SF",10);
    // cout<<s1.name<<" "<<s1.rollNo<<" "<<s1.section<<endl;
    // Student *ptr = new Student("Leela","R9P167",42);

    // cout<<ptr->name<<" "<<ptr->rollNo<<" "<<ptr->section<<endl;
    // cout<<&ptr<<endl;
    
    /*int arr[5] = {5,2,3,1,4};
    for(int i=0;i<5;i++){
        cout << arr[i]*2 << " ";
    }
    cout<<endl;
    for(int i=4;i>=0;i--){
        cout << arr[i] << " ";
    }*/

    /*int arr[10] = {2,3,1,4,5,10,18,7,12,20};
    //cout<<sum(arr);

    cout<<linearSearch(arr,10);*/


   // vector<int> arr{3,5,2,6,1};
    //selectionSort(arr);
    //bubbleSort(arr);
    
    /*for(int i : arr){
        cout<<i<<" ";
    }

    return 0;
    
    vector<int> arr1{1,2,3,0,0,0};
    vector<int> arr2{2,5,6};
    mergesort(arr1,3,arr2,3);
    for(int i: arr1){
        cout<<i<<endl;
    }
    */
    /*
    int n,m;
    cin>> n>> m;
    printEvnNumsBetNandM(n,m);
    */

    int x,n;
    cin>>x>>n;

    cout<<XpowerN(x,n);
}

