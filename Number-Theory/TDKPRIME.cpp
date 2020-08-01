/*
* https://www.spoj.com/problems/TDKPRIME/
*/
#include <bits/stdc++.h>
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define N  86028123
using namespace std;

int main()
{
    bitset <N> b;
    b[0] = b[1] = 1; // 0 and 1 are non prime
    for(int i = 2; i*i <= N; i++){
        if(!b[i]){
            for(int j = i*i; j <= N; j+= i){
                b[j] = 1;
            }
        }
    }
    int primes[5000000];
    int k = 0;
    for(int i = 2; i <= N; i++){
        if(!b[i]){
            primes[k] = i;
            k++;
        }
    }
    int n;
    cin>>n;
    int num;
    while(n--){
        cin>>num;
        cout<<primes[num-1]<<endl;
    }
    return 0;
}
