#include <bits/stdc++.h>
#include "debug.hpp"
#include "io.hpp"
typedef long long ll;
using namespace std;

/*some what similar to matrix chain multiplication
but this time I'm doing with memoizaiton technique
*/

vector<vector<ll>> dp;
vector<vector<ll>> rem;
vector<ll> num;
ll solve(ll i, ll j){
    if(i>=j){
        dp[i][j]=0;
        return 0;
    }
    if(dp[i][j]!=LLONG_MAX){
        return dp[i][j];
    }
    for(ll k=i;k<j;k++){
        dp[i][j] = min(dp[i][j], solve(i,k) + solve(k+1,j) + rem[i][k]*rem[k+1][j]);
        rem[i][j] = (rem[i][k]+ rem[k+1][j])%100;
    }
    return dp[i][j];
}

int main(){
    ll n;
    cin >> n;
    dp = vector<vector<ll>>(n+1,vector<ll>(n+1,LLONG_MAX));
    rem = vector<vector<ll>> (n+1,vector<ll>(n+1,0));
    num = vector<ll> (n);
    for(ll i=0;i<n;i++){
        cin >> num[i];
        rem[i+1][i+1] = num[i];
    }
    cout << solve(1,n) << endl;
    return 0;
}