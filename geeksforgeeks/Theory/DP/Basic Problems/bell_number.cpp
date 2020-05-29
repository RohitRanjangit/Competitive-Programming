#include <bits/stdc++.h>
#include "debug.hpp"
#include "io.hpp"
typedef long long ll;
using namespace std;


vector<vector<ll>> s;

ll solve(ll n,ll k){
    if(n<k){
        return s[n][k]=0;
    }
    if(k==1 || n==1 || k==0 || n==0 || n==k){
        return s[n][k]=1;
    }
    if(s[n][k] !=-1){
        return s[n][k];
    }
    return s[n][k] = solve(n-1,k-1) + k*solve(n-1,k);
}

int main(){
    ll n;
    cin >> n;
    s = vector<vector<ll>>(n+1,vector<ll>(n+1,-1));
    vector<ll> bell(n+1,0);
    bell[0]=1;
    for(ll i=1;i<=n;i++){
        for(ll k=1;k<=i;k++){
            bell[i] += solve(i,k);
        }
    }
    cout << bell << endl;
    return 0;
}