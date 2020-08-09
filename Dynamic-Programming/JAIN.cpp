/*
* Problem URL:
*/

#include <bits/stdc++.h>
using namespace std;

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
	FASTER;
	int t, n;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int freq_array[32] = {0};
		while(n--){
			string s;
			cin>>s;
			int mask = 0;
			for(int i = 0; i < s.size(); i++){
				switch(s[i]){
					case 'a':
						mask = mask | 1;
						break;
					case 'e':
						mask = mask | 1 << 1;
						break;
					case 'i':
						mask = mask | 1 << 2;
						break;
					case 'o':
						mask = mask | 1 << 3;
						break;
					case 'u':
						mask = mask | 1 << 4;
						break;			
				}
			}
			freq_array[mask]++;
		}
		lli count = 0;
		for(int i = 1; i < 32; i++){
			for(int j = i+1; j < 32; j++){
				if((i | j) == 31){
					count += (freq_array[i] * freq_array[j]);
				}
			}
		}
		count += freq_array[31] * (freq_array[31] - 1) / 2;
		cout<<count<<endl;
	}
	return 0;
}

