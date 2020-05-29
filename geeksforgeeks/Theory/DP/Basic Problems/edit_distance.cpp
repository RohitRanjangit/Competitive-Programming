#include <bits/stdc++.h>
#include "debug.hpp"
#include "io.hpp"
typedef long long ll;
using namespace std;


int main(){
    string s1,s2;
    cin >> s1 >> s2;
    ll m = s1.size();
    ll n = s2.size();
    vector<vector<ll>> dp(m+1,vector<ll> (n+1,0));
    for(ll i=0;i<=m;i++){
        for(ll j=0;j<=n;j++){
            if(i==0||j==0){
                dp[i][j] = max(i,j);
            }else{
                if(s1[i] == s2[j]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1+ min(min(dp[i][j-1] , dp[i-1][j-1]),dp[i-1][j]);
                }
            }
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}