#include <iostream>
#define P 1000000007
#define lli long long int
using namespace std;
void multiply_mat(lli a[][2], lli b[][2], int rows) {
	int temp[rows][2];
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < 2; j++){
			temp[i][j] = 0;
			for(int k = 0; k < 2; k++){
				temp[i][j] = (temp[i][j] + (a[i][k] * b[k][j] % P)) % P;
			}
		}
	}
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < 2; j++){
			a[i][j] = temp[i][j];
		}
	}
}
void mpow(lli a[][2], lli n){
	lli I[2][2] = {{1, 0},{0, 1}};
	while(n){
		if(n%2){
			multiply_mat(I, a, 2), n--;
		}
		else {
			multiply_mat(a, a, 2), n/= 2;
		}
	}
	for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            a[i][j] = I[i][j];
        }
    }
}
int get_fib(int a, int b, lli n){
	lli t_matrix[2][2];
	lli fib_matrix[1][2] = {a, b};
	t_matrix[0][0] = 0;
	t_matrix[0][1] = 1;
	t_matrix[1][0] = 1;
	t_matrix[1][1] = 1;
	mpow(t_matrix, n);
	multiply_mat(fib_matrix, t_matrix, 1);
	return fib_matrix[0][0];
}
int main() {
	lli q, n;
	cin>>q;
	while(q--){
		cin>>n;
		cout<<get_fib(1, 2, n-1)<<endl;
	}
}
