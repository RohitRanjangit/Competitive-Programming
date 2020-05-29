#include <bits/stdc++.h>
#include "io.hpp"
#include "debug.hpp"

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
ll n=0;
ll r,c;

vector<ll> x = {0,-1,0,1};
vector<ll> y = {-1,0,1,0};

vector<string> mat;
vector<pi> cities;
vector<vector<vector<ll>>> dist;
vector<vector<ll>> dp;
vector<string> scan_matrix(){
    cin >> r >> c;
    vector<string> str(r+2,"#");
    for(ll i=0;i<=c;i++){
        str[0] += '#';
        str[r+1] += '#';
    }
    for(ll i=0;i<r;i++){
        string temp;
        cin >> temp;
        temp += '#';
        str[i+1] += temp;
    }
    return str;
}

vector<pi> get_cities(){
    mat = scan_matrix();
    vector<pi> cities;
    for(ll i=1;i<=r;i++){
        for(ll j=1;j<=c;j++){
            if(mat[i][j] == '*'){
                cities.push_back(pi(i,j));
            }
        }
    }
    return cities;
}

bool safe(ll i, ll j){
    if(mat[i][j] == '#'){
        return false;
    }
    if(i <1 || i >r){
        return false;
    }
    if(j <1 || j>c){
        return false;
    }
    return true;
}


vector<vector<vector<ll>>> get_dist(){
    cities = get_cities();
    dist = vector<vector<vector<ll>>>(r+1,vector<vector<ll>>(c+1,vector<ll>(cities.size(),LLONG_MAX)));    
    for(ll idx=0;idx<cities.size();idx++){
        dist[cities[idx].first][cities[idx].second][idx]=0;
        queue<pi> q;
        ll v[r+1][c+1];
        memset(v,0,sizeof(v));
        q.push(cities[idx]);
        v[cities[idx].first][cities[idx].second]++;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            ll fir = front.first;
            ll sec = front.second;
            for(ll i=0;i<4;i++){
                ll xf = fir+x[i];
                ll yf = sec+y[i];
                if(v[xf][yf]==0 && safe(xf,yf)){
                    v[xf][yf]++;
                    q.push(pi(xf,yf));
                    dist[xf][yf][idx] = dist[fir][sec][idx]+1;
                }
            }
        }
    }
    return dist;
}



ll get_cost(ll mask, ll idx){
    if(mask == (1 << cities.size())-1){
        return dist[cities[0].first][cities[0].second][idx];
    }
    if(dp[idx][mask]!=LLONG_MAX){
        return dp[idx][mask];
    }
    for(ll i=0;i<cities.size();i++){
        if((mask & (1<<i)))continue;
        dp[idx][mask] = min(dp[idx][mask], get_cost(mask |1 << i,i) + dist[cities[i].first][cities[i].second][idx]);
    }
    return dp[idx][mask];
}


int main(){
    get_dist();
    debug(cities);
    dp = vector<vector<ll>>(cities.size(), vector<ll>((1 << cities.size()),LLONG_MAX));
    ll cost = get_cost(1,0);
    cout << cost << endl;
    return 0;
}