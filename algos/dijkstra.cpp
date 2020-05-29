#include <bits/stdc++.h>
#include "io.hpp"
using namespace std;

int main(){
    typedef long long ll;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;

    ll n,m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> graph(n+1,vector<pair<ll,ll>>()) ;

    for(ll i=0;i<m;i++){
        ll a,b,w;
        cin >> a >> b >> w;
        graph[a].emplace_back(b,w);
        graph[b].emplace_back(a,w);
    }


    vector<ll> weight(n+1,LLONG_MAX);
    vector<ll> parent(n+1,0);
    weight[1]=0;
    pq.push(make_pair(0,1));
    
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        for(auto next:graph[top.second]){
            if(weight[next.first] > next.second + weight[top.second] ){
                weight[next.first] = next.second + weight[top.second];
                pq.push(make_pair(weight[next.first],next.first));
                cout << make_pair(weight[next.first],next.first) << endl;
                parent[next.first] = top.second;
            }
        }
    }
    for(ll i=1;i<=n;i++){
        ll par =i;
        while(parent[par]){
            cout << par <<"->";
            par = parent[par];
        }
        cout <<"1" << endl;
        
    }
    return 0;
}