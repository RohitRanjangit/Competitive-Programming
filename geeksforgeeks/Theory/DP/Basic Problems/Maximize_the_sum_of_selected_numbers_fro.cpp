#include <bits/stdc++.h>
#include "debug.hpp"
#include "io.hpp"
typedef long long ll;
using namespace std;

int main(){
    ll n;
    cin >> n;
    vector<ll> num(n);
    map<ll,ll> mp;
    for(ll i=0;i<n;i++){
        cin >> num[i];
        mp[num[i]]++;
    }
    vector<ll> ans(mp.size(),0);
    ll idx=0;
    for(auto it:mp){
        if(idx < 2){
            ans[idx] = it.first*it.second;
        }else{
            ans[idx] = max(ans[idx-1], ans[idx-2]+it.first*it.second);
        }
        idx++;
    }
    debug(mp,ans);
    cout << ans[mp.size()-1] << endl;
    return 0;
}