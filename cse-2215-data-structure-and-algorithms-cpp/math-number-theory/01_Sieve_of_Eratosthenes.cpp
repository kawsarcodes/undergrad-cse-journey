/*
Problem(1): Generate all primes up to N efficiently.
Input 
N = 30
Output
2 3 5 7 11 13 17 19 23 29
*/

#include<iostream>
#include<vector>
using namespace std;

void sieve(int n){
    vector<bool> prime(n + 1, true);
    for(int p = 2; p * p <= n; p++){
        if(prime[p] == true){
            for(int i = p * p; i <= n; i += p){
                prime[i] = false;
            }
        }
    }
    for(int p = 2; p <= n; p++){
        if(prime[p]) cout << p << " ";
    }
}

int main(){
    int n = 30;
    cout << "Primes less than or equal to " << n << ": ";
    sieve(n);
}