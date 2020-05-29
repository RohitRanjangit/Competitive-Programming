#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
vector<vector<ll>> men;
vector<vector<ll>> caps;
vector<vector<string>> dp;
vector<vector<bool>>  men_cap;

int main(){
    cin >> n;
    string zero ="";
    for(ll i=0;i<n;i++){
        zero += '0';
    }
    dp = vector<vector<string>>(n+1,vector<string>(101,zero));
    men = vector<vector<ll>> (n+1,vector<ll>());
    caps = vector<vector<ll>> (101,vector<ll>());
    men_cap = vector<vector<bool>> (n+1,vector<bool> (101,false));
    for(ll i=0;i<n;i++){
        ll c;
        cin >> c;
        for(ll j=0;j<c;j++){
            ll temp;
            cin >> temp;
            men[i+1].push_back(temp);
            caps[temp].push_back(i+1);
            men_cap[i+1][temp] = true;
        }
    }
    for(ll i=1;i<=n;i++){
        for(auto cap :men[i]){
            // complete later
            // but I know the conecpt
        }
    }
    return 0;
}