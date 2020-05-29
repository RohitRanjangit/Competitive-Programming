#include <bits/stdc++.h>
#include "debug.hpp"
#include "io.hpp"
typedef long long ll;
using namespace std;
/*
Although memoization is fairly easy I'll do it by 
tabulation method and also by memoization
*/

ll n;
vector<ll> nums;
vector<vector<ll>> dp;

ll solve(ll i , ll j){
    if(i==j){
        return dp[i][j]=0;
    }
    if(dp[i][j]!=LLONG_MAX)return dp[i][j];
    for(ll k=i;k<j;k++){
        dp[i][j] = min(dp[i][j], solve(i,k) + solve(k+1,j) + nums[i-1]*nums[k]*nums[j]);
    }
    return dp[i][j];
}

int main(){
    cin >> n;
    nums = vector<ll>(n);
    for(ll i=0;i<n;i++)cin >> nums[i];
    dp = vector<vector<ll>>(n,vector<ll> (n,LLONG_MAX));
    cout << solve(1,n-1) << endl;
    dp = vector<vector<ll>>(n,vector<ll> (n,LLONG_MAX));
    for(ll i=0;i<n;i++)dp[i][i]=0;
    for(ll l=2;l<n;l++){
        ll s=1,e = n-l;
        for(ll i=s;i<=e;i++){
            ll j = i+l-1;
            for(ll k=i;k<j;k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + nums[i-1]*nums[k]*nums[j]);
            }
        }
    }
    cout << dp[1][n-1] << endl;
    return 0;
}