#include <bits/stdc++.h>
#include "debug.hpp"
#include "io.hpp"
typedef long long ll;
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n+1,0), b(n+1,0);
    a[1] = b[1] =1;
    for(ll i=2;i<=n;i++){
        a[i] = a[i-1] + 2*b[i-1];
        b[i] = a[i-1] + b[i-1];
    }
    cout << a[n] + 2*b[n] << endl;
    return 0;
}