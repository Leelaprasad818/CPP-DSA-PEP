
//STRINGS 


https://leetcode.com/problems/valid-palindrome-ii/?envType=problem-list-v2&envId=string
class Solution {
public:
    bool solve(string s, int i , int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        int c=1;
        while(i<j){
            if(s[i] == s[j]){
                i++;
                j--;
            }else{
                if(c != 1) return false;

                if(solve(s,i+1,j)){
                     i++;
                     c--;
                }
                else if(solve(s,i,j-1)){
                    j--;
                    c--;
                }else return false;
            }
        }

        return true;
    }
};


https://leetcode.com/problems/is-subsequence/?envType=problem-list-v2&envId=string
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l = s.size();
        int n = t.size();
        int i=0,j=0;
        
        
        while(i<l && j<n){
            if(s[i] == t[j]){
                i++;
            }
            j++;
        }

        return (i == l);
    }
};


https://www.geeksforgeeks.org/problems/find-first-repeated-character4108/1
class Solution {
  public:
    string firstRepChar(string s) {
        // code here.
        unordered_set<char> st;
        
        for(char i : s){
            if(st.find(i) != st.end()){
                string s(1,i);
                return s;
            }
            else st.insert(i);
        }
        return "-1";
    }
};