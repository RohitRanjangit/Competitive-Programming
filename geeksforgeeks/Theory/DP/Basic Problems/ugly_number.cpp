#include <bits/stdc++.h>
#include "debug.hpp"
#include "io.hpp"
typedef long long ll;
using namespace std;

int main(){
    vector<ll> vec ;
    ll n;
    cin >> n;
    vec.push_back(1);
    ll i1 =0;
    ll i2 =0;
    ll i3  =0;
    while (vec.size() <= n)
    {
        ll c1 = vec[i1]*2;
        ll c2 = vec[i2]*3;
        ll c3 = vec[i3]*5;

        ll me = min(c2,min(c1,c3));
        vec.push_back(me);

        if(me == c1){
            i1++;
        }
        if(me == c2){
            i2++;
        }
        if(me == c3){
            i3++;
        }
    }
    debug(vec);
    cout << vec[n-1] << endl;    
    return 0;
}