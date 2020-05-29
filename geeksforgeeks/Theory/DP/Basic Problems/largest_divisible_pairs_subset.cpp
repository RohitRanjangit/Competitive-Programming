#include <bits/stdc++.h>
#include "debug.hpp"
#include "io.hpp"
typedef long long ll;
using namespace std;

int main(){
    ll n;
    cin >> n;
    vector<ll> dp(n,0),num(n,0);
    for(ll i=0;i<n;i++){
        cin >> num[i];
    }
    sort(num.begin(),num.end());
    dp[0]=1;
    for(ll i=1;i<n;i++){
        ll me =0;
        for(ll j=0;j<i;j++){
            if(num[i]%num[j]==0){
                me = max(me, dp[j]);
            }
        }
        dp[i] = me+1;
    }
    ll ans =0;
    for(ll i=0;i<n;i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}