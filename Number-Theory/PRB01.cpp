/*
*   Problem: https://www.codechef.com/problems/PRB01
*/

#include <iostream>

using namespace std;

string checkPrime(int number){
    if(number == 1) return "no";
    for(int i = 2; i*i <= number; i++){
        if(number%i == 0){
            return "no";
        }
    }
    return "yes";
}
int main()
{
    int n;
    cin>>n;
    int number;
    while(n--){
        cin>>number;
        cout<<checkPrime(number)<<endl;
    }
}
