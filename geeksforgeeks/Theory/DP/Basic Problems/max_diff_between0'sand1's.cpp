#include <bits/stdc++.h>
#include "debug.hpp"
#include "io.hpp"
typedef long long ll;
using namespace std;

int main(){
    string str;
    cin >> str;
    vector<ll> vec;
    for(auto c: str){
        if(c=='0'){
            vec.push_back(1);
        }else{
            vec.push_back(-1);
        }
    }
    ll max_sum = LLONG_MIN;
    ll curr_sum=0;
    for(ll i=0;i<vec.size();i++){
        curr_sum += vec[i];
        max_sum = max(curr_sum,max_sum);
        if(curr_sum <0){
            curr_sum=0;
        }
    }
    cout << max_sum << endl;
    return 0;
}