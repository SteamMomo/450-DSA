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

int main(){
    andar_bahar();
    unordered_map<char,int> fre;
    string s;
    cin>>s;
    for(auto x: s) fre[x]++;
    for(auto it: fre) if(it.second > 1) cout<<it.first<<" ";
}
