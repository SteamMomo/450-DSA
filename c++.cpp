#include <bits/stdc++.h>

using namespace std;
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define el cout<<endl
#define sp " "
#define F first
#define S second
#define PI 3.14159265358979323846  /* pi */
#define all(v)  	((v).begin()),((v).end())
#define degreesToRadians(angleDegrees) (angleDegrees * PI / 180.0) // Converts degrees to radians.
#define radiansToDegrees(angleRadians) (angleRadians * 180.0 / PI) // Converts radians to degrees.
#define wt(t) int t=0; cin>>t; while(t--)
#define pb(a) push_back(a)
#define fa(v) for(auto x: v) cout<<x<<sp;
typedef long long ll;
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef long double ld;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
const double EPS = 1e-9;
const int N = 1e3+2, M = 3e5+5, OO = 0x3f3f3f3f;

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
	int cnt=1;
	wt(t){
		int n=0;
		cin>>n;
		string s;
		cin>>s;
		if(n%2==1) {
			int cnt=0;
			int i = (n/2);
			char c = s[i];
			while(s[i]==c && i>=0) {
				cnt++;
				i--;
			}
			cout<<max(1, (cnt*2)+1)<<endl;
		}
		else{
			int cnt=0;
			int i = (n/2)-1;
			char c = s[i];
			while(s[i]==c && i>=0) {
				cnt++;
				i--;
			}
			cout<<max(2, cnt*2)<<endl;
		}
	}
	return 0;
}
