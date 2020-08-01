/*
*   https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/prime-interval
*/
#include <iostream>
#define N 10001
using namespace std;

int main()
{
    int is_prime[N] = {0};
    is_prime[0] = is_prime[1] = 1;
    for(int i = 2; i*i <= N; i++){
        if(!is_prime[i]){
            for(int j = i*i; j <= N; j+=i){
                is_prime[j] = 1;
            }
        }
    }
    int l, r;
    cin>>l>>r;
    for(int i = l; i<= r; i++){
        if(!is_prime[i]){
            cout<<i<<" ";
        }
    }
   // cout<<endl;
    return 0;
}