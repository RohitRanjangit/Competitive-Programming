#include <bits/stdc++.h>
#include "debug.hpp"
#include "io.hpp"
typedef long long ll;
using namespace std;

int main(){
    ll n;
    cin >> n;
    vector<ll> vec(n+1,0);
    vec[0]=1;
    vec[1]=1;
    for(ll i=2;i<=n;i++){
        for(ll j=0;j<i;j++){
            vec[i] += vec[j]*vec[i-j-1];
        }
    }
    cout << vec[n] << endl;
    debug(vec);
    return 0;
}