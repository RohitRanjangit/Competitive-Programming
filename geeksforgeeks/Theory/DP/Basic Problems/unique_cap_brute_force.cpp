#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
map<ll,ll> used;
ll p=0;
ll possiblities(vector<vector<ll>> &mens,ll num){
    if(num > n)return 1;
    ll pos =0;
    for(auto caps:mens[num]){
        if(!used[caps]){
            used[caps]++;
            pos += possiblities(mens,num+1);
            used[caps]--;
        }
    }
    return pos;
}

int main(){
    cin >> n;
    vector<vector<ll>> mens(n+1,vector<ll>());
    for(ll i=0;i<n;i++){
        ll c;
        cin >> c;
        for(ll j=0;j<c;j++){
            ll temp;
            cin >> temp;
            mens[i+1].push_back(temp);
        }
    }
    cout << possiblities(mens,1) << endl;
}