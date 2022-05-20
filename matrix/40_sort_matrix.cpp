// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
//------------------------------------------------------------------------------
//Approach-1: (My apporach)
//Time complexity: O(N*N*logN), Space complexity: O(N*N)
//N*N for traversing the matrix and logN for inserting every element in map.
//N*N space for storing all the numbers in map.
//This can be done with priority queue istead of map also.(Priority queue is better than map.)
    vector<vector<int>> sortedMatrix(int n, vector<vector<int>> Mat) {
        // code here
        map<int, int> mp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mp[Mat[i][j]]++;
            }
        }
        int i=0, j=0;
        map<int, int> :: iterator it;
        for(it=mp.begin(); it!=mp.end(); it++){
            while(it->second--){
                Mat[i][j++]= it->first;
                if(j>=n){
                    j=0;
                    i++;
                }
            }
        }
        return Mat;
    }
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//Approach-2: (GFG apporach)
//Time complexity: O(N*N*logN), Space complexity: O(N*N)
void sortMat2(int mat[SIZE][SIZE], int n)
{
    // temporary matrix of size n^2
    int temp[n * n];
    int k = 0;

    // copy the elements of matrix one by one
    // into temp[]
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[k++] = mat[i][j];

    // sort temp[]
    sort(temp, temp + k);

    // copy the elements of temp[] one by one
    // in mat[][]
    k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = temp[k++];
}
//------------------------------------------------------------------------------
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}  // } Driver Code Ends
