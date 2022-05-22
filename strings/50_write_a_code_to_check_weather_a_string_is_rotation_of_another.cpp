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
    string str1, str2;
    cin>>str1;
    cin>>str2;

    str2 = str2+str2;
    if(str2.find(str1)==string::npos) cout<<"No";
    else
    cout<<"Yes";
    return 0;
}
