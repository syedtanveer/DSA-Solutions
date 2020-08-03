/*
* https://www.spoj.com/problems/MPOW/
*/
#include <iostream>
#define N 50
#define P 1000000007
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

void print_arr(long long a[][N], int dim){
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void multiply_arr(long long a[][N], long long b[][N], int dim){
    int temp[dim][dim];
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            temp[i][j] = 0;
            for(int k = 0; k < dim; k++){
                temp[i][j] = (temp[i][j] + a[i][k] * b[k][j] % P) % P;
            }
        }
    }
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            a[i][j] = temp[i][j];
        }
    }
}
void mpow(long long a[][N], int n, int dim) {
    long long id[dim][N];
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            if(j == i) id[i][j] = 1;
            else id[i][j] = 0;
        }
    }
    while(n){
        if(n%2){
            multiply_arr(id, a, dim), n--;;
        }
        else{
            multiply_arr(a, a, dim), n/=2;;
        }
    }
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            a[i][j] = id[i][j];
        }
    }
}
int main()
{
    FASTER
    int q, dim, n;
    cin>>q;
    while(q--){
        cin>>dim>>n;
        long long a[dim][N];
        for(int i = 0; i < dim; i++){
            for(int j = 0; j < dim; j++){
                cin>>a[i][j];
            }
        }
        mpow(a, n,  dim);
        print_arr(a, dim);
    }
    return 0;
}
