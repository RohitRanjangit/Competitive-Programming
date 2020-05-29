#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll find(ll node, vector<ll>& parent){
    while(node!=parent[node]){
        node = parent[node];
    }
    return node;
}

ll merge(ll node1,ll node2, vector<ll>& rank,vector<ll>& parent){
    node1 = find(node1,parent);
    node2 = find(node2,parent);

    if(rank[node2] > rank[node1]){
        parent[node1] = node2;  
    }else{
        parent[node2] = node1;
    }
    if(rank[node1] == rank[node2]){
        rank[node2]++;
    }
}


int main(){
    ll n,m;
    cin >> n >> m;
    vector<pair<ll,pair<ll,ll>>> store;
    for(ll i=0;i<m;i++){
        ll a,b,w;
        cin >> a >> b>> w;
        store.push_back(make_pair(w,make_pair(a,b)));
    }

    vector<ll> rank(n+1);
    vector<ll> parent(n+1);

    for(ll i=1;i<=n;i++){
        rank[i]  =1;
        parent[i] =i;
    }

    sort(store.begin(),store.end());
    
    ll weight =0;
    for(auto edge:store){
        if(find(edge.second.first,parent)!=find(edge.second.second,parent))
        {
            weight += edge.first;
            merge(edge.second.first,edge.second.second,rank,parent);
        }
    }

    cout << weight << endl;





    return 0;
}