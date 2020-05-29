//!solving through memoization

#include <bits/stdc++.h>
#include "debug.hpp"
#include "io.hpp"
typedef long long ll;
using namespace std;

ll nx;


map<ll,ll> dp;

ll solve(ll n){
    assert(n>=0);
    if(n <10){
        return dp[n] = (n*(n+1))/2;
    }
    if(dp[n]){
        return dp[n];
    }
    
    ll d = ll(floor(log10(n)));
    ll p= ceil(pow(10,d));
    
    if(p > n){
        p /=10;
    }
    ll msd = n/p;
    debug(n,d,p,msd);
    assert(msd);
    dp[n] = msd*(solve(p-1)) + (msd*(msd-1))/2 *(p) + msd*((n%p) + 1) + solve(n%p);
    return dp[n] ;
}

int main(){
    cin >> nx;
    cout << nx << endl;
    cout << solve(nx) << endl;
    return 0;
}