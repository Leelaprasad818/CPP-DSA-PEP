#include<iostream>

using namespace std;

bool isPalindrome(string s){
    int i = 0;
    int j = s.size()-1;
    while(i<j){
        if(s[i] == s[j]){
            i++;
            j--;
        }else return false;
    }
    return true;
}
void reverseStr(string &str){
    int n = str.size()-1;
    int k=0;
    while(k<n){
        swap(str[k],str[n]);
        n--;
        k++;
    }
}

int main(){
    string str ;
    cin>>str;

    cout<<str<<endl;
    cout<<isPalindrome(str)<<endl;
    reverseStr(str);
    cout<<str;
}





