#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll>included (n+1,0);
    vector<vector<pair<ll,ll>>> gp(n+1,vector<pair<ll,ll>>());
    for(ll i=0;i<m;i++){
        ll a,b,w;
        cin >> a >> b >> w;
        gp[a].push_back(make_pair(b,w));
        gp[b].push_back(make_pair(a,w));
    }
    vector<ll> parent(n+1,0);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    vector<ll> key(n+1,LLONG_MAX);

    key[1]=0;
    pq.push(make_pair(0,1));
    ll total =0;
    while(!pq.empty()){
        auto  top = pq.top();
        if(included[top.second]){
            pq.pop();
            continue; 
        }
        pq.pop();
        total += top.first;
        included[top.second]++;
        for(auto edge:gp[top.second]){
            if(!included[edge.first]){
                pq.push(make_pair(edge.second,edge.first));
                
                if(key[edge.first] > edge.second){
                    parent[edge.first] = top.second;
                    key[edge.first] = edge.second;
                }
            }
        }
    }

    
    cout << total << endl;
    return 0;
}