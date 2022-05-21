// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
//------------------------------------------------------------------------------
//Approach-1: (My approach)
//Time complexity: O(n*n) , Space complexity: O(k+1)
//Traverse all the elements in the matrix and store them in a priority_queue (Max heap)
//until max heap size is k, if max heap size is greater than k we pop it.
//Lastly the top of the heap element is our answer.
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  priority_queue<int> pq;
  for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
          pq.push(mat[i][j]);
          if(pq.size()>k) pq.pop();
      }
  }
  return pq.top();
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//Approach-2: (My second approach)
//Using binary search in range (x<=mat[i][j]<=y) for every mid element we check
//how many other elements are smaller by applying binary search in every row.
//Time complexity:O(), Space complexity: O(1)
int binSearch(int mat[MAX][MAX], int curr, int i, int n){
    int l=0;
    int h= n-1;
    while(l<=h){
        int mid = (l+h)/2;
        if(mat[i][mid]<=curr) l=mid+1;
        else h=mid-1;
    }
    return l;
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  int l=mat[0][0];
  int h=mat[n-1][n-1];
  int ans=0;

  while(l<=h){
      int mid = (l+h)/2;
      int cnt=0;
      for(int i=0; i<n; i++){
          cnt += binSearch(mat, mid, i, n);
      }
      if(cnt<=k-1){
          l=mid+1;
      }
      else h=mid-1;
  }
  return l;
}
//------------------------------------------------------------------------------
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
      return 0;
}
