/*
* Problem URL: https://www.codechef.com/problems/TILE
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
#define mod 1000000007
#define endl '\n'

#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef vector<int> vi;
typedef long long int lli;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;

void multiply(int a[][2], int b[][2], int rows){ //rows => row count of a
	int ans[rows][2]; // result matrix will be of size (# of_row_of_first_mat) x (# of_col_of_second_matrix)
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < 2; j++){ //j will go till no of columns in second matrix
			ans[i][j] = 0;
			for(int k = 0; k < 2; k++){ // k will go till no of rows in second matrix
				ans[i][j] = (ans[i][j] + (1LL * a[i][k] * b[k][j])%mod)%mod;
			}
		}
	}
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < 2; j++){
			a[i][j] = ans[i][j];
		}
	}
}
void mpow(int a[][2], lli n){
	int res[2][2] = {{1, 0}, {0, 1}};
	while(n){
		if(n%2){
			multiply(res, a, 2);
			n--;
		}
		else{
			multiply(a, a, 2);
			n /= 2;
		}
	}
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			a[i][j] = res[i][j];
		}
	}
}
int fib(lli n){
	int mat[1][2] = {{1, 2}};
	int t_mat[2][2] = {{0,1}, {1, 1}};
	mpow(t_mat, n-1);
	multiply(mat, t_mat, 1);
	return mat[0][0];
}

int main() {
//	FASTER;
	lli t, n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<fib(n)<<endl;
	}
	return 0;
}

