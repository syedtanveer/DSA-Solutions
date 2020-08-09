/*
*	https://www.codechef.com/problems/GCDMOD
*/

#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define P 1000000007
#define lli long long int

using namespace std;

lli power(lli a, lli n, lli d) {
	lli res = 1;
	while(n) {
		if(n&1){
			res = ((res%d) * (a%d))%d; n--;
		}
		else {
			a = ((a%d)*(a%d))%d; n/=2;
		}
	}
	return res;
}
lli gcd(lli a, lli b, lli n){
	if(a == b) return (2*power(a, n, P))%P;
	lli g = 1;
	lli num = a-b;
	
		for(lli i = 1; i*i <= num; i++){
			if(num%i == 0){
				if((power(a, n, i) + power(b, n, i))%i == 0){
					g = max(g,i);
				}
				if((power(a, n, num/i) + power(b, n, num/i))%(num/i) == 0){
					g = max(g,num/i);
				}
			}
		}
		return g%P;
}
int main() {
	lli t,a, b, n;
	cin>>t;
	while(t--){
		cin>>a>>b>>n;
		cout<<gcd(a, b, n)<<endl;
	}
	return 0;
}

