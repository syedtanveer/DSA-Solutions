/*
* https://www.codechef.com/problems/GCDQ/
*/
#include <iostream>

#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
int gcd(int a, int b){
	while(b != 0 && a != 0){
		if(a >= b){
			a %= b;
		}
		else{
			b %= a;
		}
	}
	return a == 0 ? b : a;
}
int main() {
	FASTER
	int t, n, q, l, r;
	cin>>t;
	while(t--){
		cin>>n>>q;
		int a[n+1];
		int pre[n+1];
		int suf[n+2];
		for(int i = 1; i <= n; i++) cin>>a[i];
		pre[1] = a[1];
		suf[n] = a[n];
		suf[n+1] = 0;
		pre[0] = 0;
		for(int i = 2; i <= n; i++) pre[i] = gcd(pre[i-1], a[i]);
		for(int i = n-1; i >= 1; i--) suf[i] =  gcd(suf[i+1], a[i]);
		while(q--){
			cin>>l>>r;
			cout<<gcd(pre[l-1], suf[r+1])<<endl;
		}
	}
}
