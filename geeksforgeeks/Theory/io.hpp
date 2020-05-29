#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
template
<typename T>
ostream &operator<<(ostream& out, vector<T> const& vec){
    out << "vector(";
    for( ll i=0;i<vec.size();i++){
        if(!i)out << vec[i];
        else out << ", " << vec[i];
        
    }
    out << ")";
    return out;
}

template
<typename K,typename V>
ostream &operator<<(ostream& out,map<K,V> const& mp){
    out << "map{";
    bool yes = true;
    for(auto it:mp){
        if(yes) {
            out << it.first<<":"<< it.second;
            yes = false;
        }
        else out <<", " <<  it.first<<":"<< it.second;
        
    }
    out <<"}";
    return out;
}

template
<typename O,typename T>
ostream &operator<<(ostream& out, pair<O,T> const &p){
    out << "pair(" << p.first << ", " << p.second <<")";
    return out;
}

template
<typename Q,typename P, typename R>
ostream &operator<<(ostream& out, priority_queue<Q,P,R>const&  pq1){
    auto pq  =pq1;
    out << "priority_queue{{ ";
    while(!pq.empty()){
        out << pq.top() <<", ";
        pq.pop();
    }
    out << " }}";
    return out;
}

