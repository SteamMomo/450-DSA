//------------------------------------------------------------------------------
//Approach-1: Traverse from left and right and swap.
//Time complexity: O(n), Space complexity: O(1)
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            swap(s[i++],s[j--]);
        }
    }
};
//------------------------------------------------------------------------------
