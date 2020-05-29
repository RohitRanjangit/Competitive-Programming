#include <bits/stdc++.h>
#include "debug.hpp"
#include "io.hpp"
typedef long long ll;
using namespace std;

int main(){
    ll n,m;
    cin >> n >> m;
    
    vector<bool> DP(m,false);
    vector<ll> arr(n);

    for(ll i=0;i<n;i++){
        cin >> arr[i];
    }
    if(n > m ){
        cout << "YES" << endl;
        return 0;
    }
    for(ll i=0;i<n;i++){
        debug(DP);
        if(DP[0]){
            cout << "YES" << endl;
            return 0;
        }
        vector<bool> temp(m,false);
        for(ll j=0;j<m;j++){
            if(DP[j]){
                temp[(arr[i]+j)%m] = true;
            }
        }
        DP[arr[i]%m] = true;
        for(ll j=0;j<m;j++){
            if(temp[j])DP[j] = temp[j];
        }
    }
    debug(DP);
    if(DP[0]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    
    return 0;
}