//Approach-1: (My solution) Time complexity = O(n) + O(logn)
//Linear search in first coloumn of matrix then binary search in that row.
class Solution {
public:

    bool binSearch(vector<int> v, int target){
        int l = 0;
        int r = v.size()-1;

        while(l<=r){
            int mid = (l+r)/2;
            if(v[mid]<target) l=mid+1;
            else if(v[mid]>target) r=mid-1;
            else if(v[mid]==target) return true;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int pos = 0;
        for(int i=0; i< matrix.size(); i++){
            if(matrix[i][0]<=target) pos =i;
        }
        if(matrix[pos][0]==target) return true;
        return binSearch(matrix[pos], target);
    }
};

//Appoach-2: (Mind blowing apporach) Easiest
//Given matix can be treated as a binary search tree.
//Given matrix:
// 1  3  5  7
// 10 11 16 20
// 23 30 34 60
//When we tilt the given matrix we get a bst.
//      7
//    5    20
//  3    16    60
//1    11    34
//  10     30
//      23
//Worst case time complexity = O(n) (Incase there is only one row.)

class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col= matrix[0].size()-1;
        int row=0;
        int maxRow = matrix.size();

        while(row<maxRow && col>-1){
            int x = matrix[row][col];

            if(x<target) row++;
            else if(x>target) col--;
            else if(x==target) return true;
        }
        return false;
    }
};
