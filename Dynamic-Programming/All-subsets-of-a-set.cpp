/*
* Problem URL:
*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define sz(w) (int) w.size()

#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef vector<int> vi;
typedef long long int lli;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;

int main() {
	char s[5] = {'A', 'B', 'C', 'D', 'E'};
	int t, n;
	cin>>t;
	//vector<vector<char> > power_set;
	while(t--){
	cin>>n;
	for(int i = 0; i < (1 << n); i++){ //runs till 2^n
		//vector<char> v;
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				//v.pb(s[j]);
				cout<<s[j]<<" ";
			}
		}
		cout<<endl;
	}
}
	return 0;
}

