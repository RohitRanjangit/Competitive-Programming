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
    if(i>=j){
        return dp[i][j]=0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
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
    return 0;
}