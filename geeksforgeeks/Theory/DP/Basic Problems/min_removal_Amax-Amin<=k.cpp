#include <bits/stdc++.h>
#include "debug.hpp"
#include "io.hpp"
typedef long long ll;
using namespace std;
ll n,k;
vector<vector<ll>> dp;
int main(){
    cin >> n >> k;
    dp = vector<vector<ll>> (n+1,vector<ll> (k+1,0));
    vector<ll> num(n+1,0);
    for(ll i=1;i<=n;i++)cin >> num[i];
    for(ll i=1;i<=n;i++){
        for(ll diff = 0;diff <= k;diff++){
            if(diff - num[i] + num[i-1] >=0)dp[i][diff] = max(dp[i-1][diff - num[i]+num[i-1]]+1 , dp[i-1][diff]);
            else dp[i][diff] = max(ll(1) , dp[i-1][diff]);
        }
    }
    debug(dp);
    cout << dp[n][k] << endl;
    return 0;
}