// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{

    void fun(string s, int l, int r,  vector<string> &ans){
        if(l==r){
             ans.push_back(s);
             return;
        }

        for(int i=l;i<r ;i++){
            swap(s[i], s[l]);
            fun(s, l+1, r, ans);
            swap(s[i],s[l]);
        }
    }

	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans(0);
		    fun(S, 0, S.length(), ans);

		    sort(ans.begin(), ans.end());
		    ans.erase(unique(ans.begin(), ans.end()), ans.end());
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
int main(){
    andar_bahar();
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<"\n";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends
