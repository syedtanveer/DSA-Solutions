/*
*   hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/micro-and-prime-prime-1
*/
#include <iostream>
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define N 1000001
using namespace std;

int main()
{
    FASTER
    int is_prime[N] = {0};
    is_prime[0] = is_prime[1] = 1;
    for(int i = 2; i*i <= N; i++){
        if(!is_prime[i]){
            for(int j = i*i; j <= N; j+=i){
                is_prime[j] = 1;
            }
        }
    }

    int pprimes_till_n[N] = {0};
    int count = 0;
    for(int i = 1; i < N; i++){
        if(!is_prime[i]) count++;
        if(!is_prime[count]){
            pprimes_till_n[i] = pprimes_till_n[i-1] + 1;
        }
        else{
            pprimes_till_n[i] = pprimes_till_n[i-1];
        }
    }
    int q, l, r;
    cin>>q;
    while(q--){
        cin>>l>>r;
        cout<<pprimes_till_n[r]-pprimes_till_n[l-1]<<endl;
    }
    return 0;
}
