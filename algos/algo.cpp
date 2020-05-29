#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
//!log10 also fails for 999999999999999999999
// it will retrurn number of digits+1 that's not what we want

/*
1.)to calculate greatest integer that less than or equal to a use:
upper_bound(vec.begin(),vec.end(),a)--;
2.)to find smallest integer greatet than or equal to a use:
lower_bound(vec.begin(),vec.end(),a);
*/
/*
insertion and deletion works faster in case set
...
set<ll> s;
s.insert(num1);
s.erase(num1);
*/
//return gcd of two element
ll gcd(ll a, ll b){
    if(b>a)return gcd(b,a);
    if(a%b)return gcd(b,a%b);
    return b;
}

//returns max element of map based on second element
template
<
typename Key =ll,
typename Val = ll
>
auto max_mp(map<Key,Val>&mp){
    auto max_e = mp.begin();
    auto it = mp.begin();
    while(it!=mp.end()){
        if(it->second > max_e->second){
            max_e = it;
        }
        it++;
    }
    return *max_e;
}
//returns min element of map based on second element
template
<
typename Key =ll,
typename Val = ll
>
auto min_mp(map<Key,Val>&mp){
    auto min_e = mp.begin();
    auto it = mp.begin();
    while(it!=mp.end()){
        if(it->second < min_e->second){
            min_e = it;
        }
        it++;
    }
    return *min_e;
}


//use it for pair sorting if we want to sort using second
bool sortbysec(const pair<ll,ll> &a,const pair<ll,ll> &b){ 
    return a.second < b.second;   
}
//use it for pair sorting if we want to sort using first
bool sortbyfir(const pair<ll,ll> &a,const pair<ll,ll> &b){ 
    return (a.first < b.first); 
}


//efficient way to calculate pow(n,i)
ll multiply(ll n,ll i){
    if(i==1){
        return n;
    }
    if(i==0){
        return 1;
    }
    ll half = multiply(n,floor(ld(i)/2));
    return (half*half*multiply(n,i-2*floor(ld(i)/2)));
}

//efficient way to generate all primes less than equal to n
vector<ll> generate_prime(ll n) { 
    vector<bool> prime(n+1,true);
    for (ll p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (ll i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    vector<ll> pr;
    for (ll p=2; p<=n; p++) 
       if (prime[p]) 
          pr.push_back(p);
    return pr;
}

int getClosest(int, int, int); 
int findClosest(vector<int> &arr, int n, int target) 
{ 
    if (target <= arr[0]) 
        return arr[0]; 
    if (target >= arr[n - 1]) 
        return arr[n - 1]; 
    int i = 0, j = n, mid = 0; 
    while (i < j) { 
        mid = (i + j) / 2; 
        if (arr[mid] == target) 
            return arr[mid];
        if (target < arr[mid]) { 
            if (mid > 0 && target > arr[mid - 1]) 
                return getClosest(arr[mid - 1], 
                                  arr[mid], target); 
            j = mid; 
        } 
        else { 
            if (mid < n - 1 && target < arr[mid + 1]) 
                return getClosest(arr[mid], 
                                  arr[mid + 1], target); 
            i = mid + 1;  
        } 
    } 
  
    return arr[mid]; 
} 
int getClosest(int val1, int val2, 
               int target) 
{ 
    if (target - val1 >= val2 - target) 
        return val2; 
    else
        return val1; 
} 
