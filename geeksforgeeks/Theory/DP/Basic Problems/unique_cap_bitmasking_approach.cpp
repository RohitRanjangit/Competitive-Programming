#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include "io.hpp"
#include "debug.hpp"

ll n;

vector<vector<ll>> caps(101,vector<ll>());
ll dp[1025][101];

ll ways(ll mask ,ll cap){
    if(mask == (1<<n) - 1){
        return 1;
    }
    if(cap > 100){
        return 0;
    }
    if(dp[mask][cap]!=-1){
        return dp[mask][cap];
    }
    dp[mask][cap] = ways(mask,cap+1);
    for(auto m:caps[cap]){
        if((1 << m-1) & mask)continue;
        dp[mask][cap] += ways(mask|1<<(m-1) ,cap+1);
    }
    return dp[mask][cap];
}

int main(){
    memset(dp,-1,sizeof(dp));

    
    cin >> n;
    for(ll i=0;i<n;i++){
        ll c;
        cin >> c;
        for(ll j=0;j<c;j++){
            ll temp;
            cin >> temp;
            caps[temp].push_back(i+1);
        }
    }
    
    cout << ways(0,1) << endl;
    return 0;
}