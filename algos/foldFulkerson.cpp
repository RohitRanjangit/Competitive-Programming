#include <bits/stdc++.h>
#define Point pair<ll,ll>
typedef long long ll;

using namespace std;


bool augmenting_path(vector<vector<ll>>& gp,map<Point,ll>& capacity,vector<ll>& parent, ll s ,ll t, ll n){
    vector<bool> v(n+1,false);
    v[s] = true;
    queue<ll> q;
    q.push(s);
    parent[s] =0;
    while(!q.empty()){
        ll front = q.front();
        q.pop();
        for(auto next:gp[front]){
            if(v[next] == false && capacity[Point(front,next)]){
                q.push(next);
                v[next] = true;
                parent[next] =front;
            }
        }
    }
    return v[t];
}

ll fold_fulkerson(vector<vector<ll>>& gp,map<Point,ll>& capacity , ll s, ll t, ll n){
    ll max_flow=0;
    vector<ll> parent(n+1,0);
    
    while(augmenting_path(gp,capacity,parent,s,t,n)){
        
        ll path_flow =  LLONG_MAX;
        ll sink =t;
        while(parent[sink]){
            path_flow = min(path_flow, capacity[Point(parent[sink],sink)]);
            sink = parent[sink];
        }
        sink =t;
        while(parent[sink]){
            capacity[Point(parent[sink],sink)] -= path_flow;
            capacity[Point(sink,parent[sink])] += path_flow;
            sink  = parent[sink];
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main(){
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> gp(n+1,vector<ll>());
    map<Point,ll> capacity;

    for(ll i=0;i<m;i++){
        ll a,b,w;
        cin >> a >> b >> w;
        gp[a].push_back(b);
        capacity[Point(a,b)] =w;
    }

    ll s,t;
    cin >> s >> t;

    cout << fold_fulkerson(gp,capacity,s,t,n) << endl;
    
    return 0;
}