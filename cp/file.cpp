#include <bits/stdc++.h>
using namespace std;
#if __has_include("io.hpp")
# include "io.hpp"
#endif
#if __has_include("debug.hpp")
# include "debug.hpp"
#endif
typedef long long ll;
typedef long double ld;
typedef pair<ll,pair<ll,ll>> pii;
typedef pair<ll,ll> pi;
#define PI 3.14159265358979323846264338
#define matrix vector<vector<ll>>
#define llmax LLONG_MAX
#define llmin LLONG_MIN
#define loop(i,n) for(ll (i)=0;(i)<n;(i)++)
#define cloop(i,m,n) for(ll (i)=m;(i)<n;(i)++)
#define zero(a) memset((a),0,sizeof((a)))
#define minus(a) memset((a),-1,sizeof((a)));
#define sq(a) ((a)*(a))
#define mod 1000000007
ll global=0;

void test_case(ll);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #if __has_include("io.hpp")
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    #endif
    //**************************************************************************//
    ll t;
    int yes = 1;
    if(yes)cin >> t;
    else t=1;
    for(ll T=0;T<t;T++){
        test_case(T);
    }
    //**************************************************************************//
    return 0;
}


void test_case(ll T){
    ll n,x;
    cin >> n >> x;
    vector<ll> days(2*n);
    vector<ll> pre(2*n);
    loop(i,2*n){
        if(i<n)cin >> days[i];
        else days[i] = days[i-n];
        if(i==0){
            pre[i] = (days[i]*(days[i]+1))/2;
        }
        pre[i] = pre[i-1] + (days[i]*(days[i]+1))/2;
    }
    
} 