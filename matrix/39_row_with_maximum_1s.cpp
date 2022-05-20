// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	//--------------------------------------------------------------------------
	//Approach-1: (My apporach/ Naive approach)
	//Traverse every row and store the row index with maximum 1's
	//Time complexity: O(n*m) , Space complexity: O(1)
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int maxSum=0, pos=-1;
	    int tempSum=0;
	    for(int i=0; i<n ;i++){

	        for(auto x: arr[i]) if(x==1) tempSum++;
	        if(tempSum>maxSum){
	            maxSum= tempSum;
	            pos = i;
	        }
	        tempSum=0;
	    }
	    return pos;
	}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//Approach-2: (Optimal approach)
//Start from first row and last column
//if (arr[i][j] == 1)
//decrement j by one and keep the index of row (reverse Traverse the row)
//else
//increment i by one (go to next coloumn)
//at last return the index.
int rowWithMax1s2(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int i=0, j=m-1;
	    int ans=-1;
	    while(i<n && j>-1){
	        if(arr[i][j]) {
	            j--;
	            ans=i;
	        }
	        else i++;
	    }
	    return ans;
	}
//------------------------------------------------------------------------------

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
