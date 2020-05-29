#include <bits/stdc++.h>
#include "debug.hpp"
#include "io.hpp"
typedef long long ll;
using namespace std;

int main(){
    int h;
    cin >> h;
    vector<ll> poss(h+1,0);
    poss[0] = poss[1] =1;
    for(ll i=2;i<=h;i++){
        poss[i] = poss[i-1]*poss[i-1] + 2*poss[i-1]*poss[i-2];
    }
    cout << poss[h] << endl;
    return 0;
}