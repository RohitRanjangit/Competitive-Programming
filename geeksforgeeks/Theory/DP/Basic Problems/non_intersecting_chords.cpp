#include <bits/stdc++.h>
#include "debug.hpp"
#include "io.hpp"
typedef long long ll;
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<ll> dp(n+1,0);
    dp[0]=dp[1]=1;
    for(ll i=2;i<=n;i++){
        for(ll j=0;j<=i-1;j++){
            dp[i] += dp[j]*dp[i-j-1];
        }
    }
    cout << dp[n] << endl;
    return 0;
}