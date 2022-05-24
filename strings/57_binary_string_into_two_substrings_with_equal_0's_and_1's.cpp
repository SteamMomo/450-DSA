#include <bits/stdc++.h>

using namespace std;

void andar_bahar(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}

int main (){
	andar_bahar();
	int c0=0;
	int c1=0;
	string s;
	cin>>s;
	int n = s.length();
	int ans=0;
	for(int i=0; i<n; i++){
		if(c0==c1) {
			ans++;
			c0=0;c1=0;
		}
		if(s[i]=='1') c1++;
		else c0++;
	}
	if(c0!=c1) ans = -1;
	cout<<ans;
	return 0;
}
