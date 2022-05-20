// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
//------------------------------------------------------------
//Approach-1:(My apporach/Naive approach)
//Store the given matrix in a 1D vector then sort it using merge sort and return median.
//Time complexity: O(r*c*log(r*c)), Space complexity: O(r*c)
    void merge(vector<int> &v, int l, int mid, int r){
        int n1= mid-l+1;
        int n2= r-mid;

        vector<int> v1(n1), v2(n2);
        for(int i=0; i<n1; i++) v1[i]= v[l+i];
        for(int i=0; i<n2; i++) v2[i]= v[mid+1+i];
        int k=l, i=0, j=0;
        while(i<n1 && j<n2){
            if(v1[i]<v2[j]) v[k++]= v1[i++];
            else v[k++]= v2[j++];
        }
        while(i<n1) v[k++]= v1[i++];
        while(j<n2) v[k++]= v2[j++];
    }

    void mergeSort(vector<int> &v, int l, int r){
        if(l<r){
            int mid = (l+r)/2;
            mergeSort(v, l, mid);
            mergeSort(v, mid+1, r);
            merge(v, l, mid, r);
        }
        else return;
    }

    int median(vector<vector<int>> &matrix, int r, int c){
        // code here
        vector<int> v;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                v.push_back(matrix[i][j]);
            }
        }
        mergeSort(v, 0, v.size()-1);
        return v[v.size()/2];
    }
//--------------------------------------------------------------------

//--------------------------------------------------------------------
//Approach-2: (Optimal approach, Binary Search)
//Let the given array be : 1 2 3 4 5 6 7
//Here the median will be 4 because there are 3 elements on the left side of 4 and
//exactly 3 elements on the right side of 4.
//In the given range (x<=matrix[i][j]<=y) by binary search we find the element that has
//exactly (r*c)/2 elements less than itself.
//Time complexity: log2(2^32)*r*log(c) = 32*r*log(c)
    int binSearch(vector<int> v, int curr){
        int l=0, r=v.size()-1;
        while(l<=r){
            int mid= (l+r)/2;
            if(v[mid]<=curr) {
                l= mid+1;
            }
            else r= mid-1;
        }
        return l;
    }

    int binNums(vector<vector<int>> &matrix, int r, int c, int curr){
        int res=0;
        for(int i=0; i<r; i++){
            res += binSearch(matrix[i], curr);
        }
        return res;
    }

    int median2(vector<vector<int>> &matrix, int r, int c){
        // code here
        int target= (r*c)/2;
        int l=0, h=20001;
        while(l<=h){
            int mid=(l+h)/2;
            int temp =binNums(matrix, r, c, mid);
            if(temp<=target) l=mid+1;
            else if(temp>target) h= mid-1;
        }
        return l;
    }
//------------------------------------------------------------------------------

};


// { Driver Code Starts.
void andar_bahar(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int main()
{
    andar_bahar();
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
        for(int j = 0;j < c; ++j)
        cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;
    }
    return 0;
}  // } Driver Code Ends
