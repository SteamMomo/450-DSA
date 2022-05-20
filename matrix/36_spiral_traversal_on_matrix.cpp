// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1#
 // } Driver Code Ends
class Solution
{
    public:
    //Function to return a list of integers denoting spiral traversal of matrix.
    //Approach-1: top, down, left, right are inclusive. be careful about the matrix indexing.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c)
    {
        // code here
        int i=0, j=0;
        int down=r-1, right=c-1;
        int up=0, left=0;
        vector<int> ans(0);
        int dir=0;
        while(left<=right && up<=down){
            if(dir==0){
                j=left;
                while(j<=right){
                    ans.push_back(matrix[up][j++]);
                }
                up++;
            }
            else if(dir==1){
                i=up;
                while(i<=down){
                    ans.push_back(matrix[i++][right]);
                }
                right--;
            }
            else if(dir==2){
                j=right;
                while(j>=left){
                    ans.push_back(matrix[down][j--]);
                }
                down--;
            }
            else if(dir==3){
                i=down;
                while(i>=up){
                    ans.push_back(matrix[i--][left]);
                }
                left++;
            }
            dir = (dir+1)%4;
        }
        return ans;
    }
};

void andar_bahar(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}

// { Driver Code Starts.
int main() {
    andar_bahar();
    int t;
    cin>>t;

    while(t--)
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r);

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
