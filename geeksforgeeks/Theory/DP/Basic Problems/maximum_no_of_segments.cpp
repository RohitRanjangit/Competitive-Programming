#include <bits/stdc++.h>
#include "debug.hpp"
#include "io.hpp"
typedef long long ll;
using namespace std;

int main(){
    ll n;
    ll a,b,c;
    cin >> n;
    cin >> a >> b >> c;
    vector<ll> seg(n+1,0);
    for(ll i=1;i<=n;i++){
        if(i-a>=0){
            if(i-a!=0){
                if(seg[i-a]){
                    seg[i] = max(seg[i],seg[i-a]+1);
                }
            }else{
                seg[i] = max(seg[i],ll(1));
            }
        }
        if(i-b>=0){
            if(i-b!=0){
                if(seg[i-b]){
                    seg[i] = max(seg[i],seg[i-b]+1);
                }
            }else{
                seg[i] = max(seg[i],ll(1));
            }
        }
        if(i-c>=0){
            if(i-c!=0){
                if(seg[i-c]){
                    seg[i] = max(seg[i],seg[i-c]+1);
                }
            }else{
                seg[i] = max(seg[i],ll(1));
            }
        }
        
    }
    debug(seg);
    cout << seg[n] << endl;
    return 0;
}