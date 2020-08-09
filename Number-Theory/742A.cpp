/*
*	https://codeforces.com/problemset/problem/742/A
*/
#include <iostream>

using namespace std;

int power(int a, int n){
	int res = 1;
	while(n){
		if(n%2){
			res = (res%10 * a)%10;
			n--;
		}
		else{
			a = (a*a)%10;
			n /= 2;
		}
	}
	return res;
}

int main(){
	int n;
	cin>>n;
	cout<<power(8, n);
}
