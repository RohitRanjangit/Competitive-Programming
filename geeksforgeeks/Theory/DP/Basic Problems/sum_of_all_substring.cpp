#include <bits/stdc++.h>
#include "debug.hpp"
#include "io.hpp"
typedef long long ll;
using namespace std;

int main(){
    string str;
    cin >> str;
    ll n = str.size();
    vector<ll> till_sum(str.size()+1,0);
    ll res =0;
    for(ll i=1;i<=n;i++){
        till_sum[i] = i*(str[i-1]-'0') + 10*till_sum[i-1];
        res += till_sum[i];
    }
    cout << res << endl;
    return 0;
}