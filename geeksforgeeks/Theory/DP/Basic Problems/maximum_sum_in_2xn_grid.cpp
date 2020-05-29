#include <bits/stdc++.h>
#include "debug.hpp"
#include "io.hpp"
typedef long long ll;
using namespace std;

int main(){
    ll n;
    cin >> n;
    vector<vector<ll>> num(2,vector<ll>());
    vector<ll> sum(n+1,0);
    for(ll i=0;i<n;i++){
        ll temp;
        cin >> temp;
        num[0].push_back(temp);
    }
    for(ll i=0;i<n;i++){
        ll temp;
        cin >> temp;
        num[1].push_back(temp);
    }
    sum[1]= max(num[0][0],num[1][0]);
    for(ll i=2;i<=n;i++){
        sum[i] = max(sum[i-1],sum[i-2] + max(num[0][i-1],num[1][i-1]));
    }
    debug(sum);
    cout << sum[n] << endl;
    return 0;
}