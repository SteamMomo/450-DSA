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
//Approach-1: Recursion
void printAllSubsequences(string str, string output){
    if(str.empty()){
        cout<<output<<endl;
        return;
    }
    printAllSubsequences(str.substr(1), output+str[0]);
    printAllSubsequences(str.substr(1), output);
}
//------------------------------------------------------------------------------

int main(){
    andar_bahar();
    printAllSubsequences("ABCD", "");
    return 0;
}
