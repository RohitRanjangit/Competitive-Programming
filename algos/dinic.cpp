#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


bool bfs(vector<vector<ll>> &gp,vector<ll>& level, ll s, ll t,map<pair<ll,ll>,ll>& caps){
    ll n = gp.size();
    level = vector<ll>(n,0);
    level[s]++;
    queue<ll> q;
    q.push(s);
    while(!q.empty()){
        ll front = q.front();
        q.pop();
        for(auto next:gp[front]){
            if(level[next] == 0 && caps[pair<ll,ll>(front,next)]){
                level[next] = level[front] +1;
                q.push(next);
            }
        }
    }
    return level[t]!=0;
}

ll send_flow(vector<vector<ll>>& gp, map<pair<ll,ll>,ll>& caps,ll s, ll t, ll flow , vector<bool>&v,vector<ll> & level){
    v[s] = true;
    if(s==t){
        return flow;
    }
    
    for(auto next :gp[s]){
        if(v[next] == false && caps[pair<ll,ll>(s,next)] && level[next] == level[s]+1){
            ll curr_flow = min(caps[pair<ll,ll>(s,next)],flow);
            curr_flow = send_flow(gp,caps,next,t,curr_flow,v,level);
            if(curr_flow){
                caps[pair<ll,ll>(s,next)] -= curr_flow;
                caps[pair<ll,ll>(next,s)] += curr_flow;
                return curr_flow;
            }
        }
    }

    return 0;
}

int main(){
    int n,m;
    cin >> n >> m;
    assert(n >0 && m >0 );
    vector<vector<ll>> gp(n+1,vector<ll>());
    map<pair<ll,ll>,ll> caps;

    for(ll i=0;i<m;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        gp[a].push_back(b);
        caps[pair<ll,ll>(a,b)] =c;
    }

    vector<ll> level(n+1,0);
    ll s,t;
    cin >> s >> t;
    assert(s >0 && t >0);

    ll total =0;
    while(bfs(gp,level,s,t,caps)){
        vector<bool> v(n+1,false);
        while(ll flow = send_flow(gp,caps,s,t,LLONG_MAX,v,level)){
            cout << "calculating..." << endl;
            total += flow;
        }
    }
    

    cout << total << endl;

    return 0;
}