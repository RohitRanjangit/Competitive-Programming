#include <bits/stdc++.h>
#include "debug.hpp"
#include "io.hpp"
typedef long long ll;
using namespace std;


//! using tabulization technique
int main(){
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> mines(n+2,vector<ll>());
    mines[0] = vector<ll>(m,0);
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<m;j++){
            ll temp;
            cin >> temp;
            mines[i].push_back(temp);
        }
    }
    mines[n+1] = vector<ll>(m,0);
    for(ll j=1;j<m;j++){
        for(ll i=1;i<=n;i++){
            mines[i][j] += max(max(mines[i-1][j-1],mines[i+1][j-1]),mines[i][j-1]);
        }
    }
    ll res = LLONG_MIN;
    for(ll i=0;i<=n;i++){
        res = max(res,mines[i][m-1]);
    }
    cout << res << endl;
    return 0;
}