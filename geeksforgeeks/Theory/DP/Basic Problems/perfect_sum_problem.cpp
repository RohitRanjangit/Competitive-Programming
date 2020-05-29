#include <bits/stdc++.h>
#include "debug.hpp"
#include "io.hpp"
typedef long long ll;
using namespace std;

int main(){
    ll n,s;
    cin >> n >> s;
    vector<ll> num(n);
    for(ll i=0;i<n;i++){
        cin >> num[i];
    }
    ll dp[n+1][s+1];
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(ll sm=1;sm<=s;sm++){
        for(ll i=1;i<=n;i++){
            if(sm - num[i-1] >=0){
                dp[i][sm] += dp[i-1][sm-num[i-1]];
            }
            dp[i][sm] += dp[i-1][sm];
        }
    }
    cout << dp[n][s] << endl;
    return 0;
}