#include<bits/stdc++.h>

using namespace std;

void andar_bahar(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
//------------------------------------------------------------------------------
//Approach-1:(My approach/Recursion)
//Still dont know what temp +='&' does.
//Time complexity:
string countAndSay(int n) {
    if(n==0) return "0";
    if(n==1) return "1";

    string temp = countAndSay(n-1);
    string ans="";
    int cnt=1;
    char c= temp[0];
    temp +='&';
    for(int i=1; i<temp.size(); i++){
        if(temp[i]==c) cnt++;
        else {
            ans = ans + to_string(cnt);
            ans.push_back(c);
            c=temp[i];
            cnt=1;
        }
    }
    return ans;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//Approach-1:(Iteration)
//Time complexity: n*n
string countAndSay2(int n) {
    if (n == 0) return "";
    string res = "1";
    while (--n) {
        string cur = "";
        for (int i = 0; i < res.size(); i++) {
            int count = 1;
             while ((i + 1 < res.size()) && (res[i] == res[i + 1])){
                count++;
                i++;
            }
            cur += to_string(count) + res[i];
        }
        res = cur;
    }
    return res;
}
//------------------------------------------------------------------------------

int main(){
    andar_bahar();
    cout<<countAndSay(4);
    cout<<endl;
    cout<<countAndSay2(4);
    return 0;
}
