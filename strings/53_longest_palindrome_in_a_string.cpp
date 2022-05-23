// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
//------------------------------------------------------------------------------
//Approach-1: (Dynamic Programming)
//x..abc..y = Here if x==y and abc is a planindrome then x..abc..y is a palindrome
//also. We check if inner substring is palindrome or not then store in 2d array.
//Time complexity: O(n*n), Space complexity: O(n*n);
    string longestPalin (string S) {
        // code here
        int n=S.length();
        int arr[n][n]={0};
        for(int i=0; i<n; i++){
            arr[i][i]=1;
        }
        int ans=1, x=0, y=0;
        for(int j=1, i=0; j<n; j++, i++){
            if(S[i]==S[j]){
                arr[i][j]=1;
                if(j-i+1 > ans){
                    ans= j-i+1;
                    x=i;y=j;
                }
            }
        }
        for(int j=2; j<n; j++){
            for(int i=0, k=j; i<n && k<n; i++, k++){
                if(S[i]==S[k] && arr[i+1][k-1]==1){
                    arr[i][k]=1;
                    if(k-i+1 > ans){
                        ans= k-i+1;
                        x=i;y=k;
                    }
                }
            }
        }
        string res;
        for(int i=x ; i<=y; i++) res.push_back(S[i]);
        return res;
    }
};
//------------------------------------------------------------------------------
// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
