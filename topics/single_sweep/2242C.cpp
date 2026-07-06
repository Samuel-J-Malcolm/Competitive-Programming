/*
Link: https://codeforces.com/contest/2242/problem/C
Rating:
Platform:
Duration: 
*/

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#include <iomanip>

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;


using ll  = long long;
using ull = unsigned long long;
using ld  = long double;

using pintint = pair<int, int>;
using pintl = pair<int, ll>;
using pll = pair<ll, ll>;

using vint  = vector<int>;
using vll = vector<ll>;
using vvint = vector<vint>;
using vvll = vector<vll>;

// Macros
#define pb    push_back
#define eb    emplace_back
#define mp    make_pair
#define fi    first
#define se    second
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x)   (ll)(x).size()
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define repp(i, a, b, c) for (ll i = (a); i < (b); i+=c)
#define repn(i, a, b, c) for (ll i = (a); i > (b); i-=c)

using str = string;

#define NO cout << ("NO"); return;
#define YES cout << ("YES"); return;

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif


// Constants
const ll INF  = 1e18;
const ll INF32 = 1e9;
const ld  EPS = 1e-9;
const ll  MOD = 1e9 + 7;

void printstruct(auto& s){
    cout << "(";
    for(auto c: s){
        cout << c << " ";
    }
    cout << ")";
    cout << "\n";
    
}


void solve()
{
    ll m,n,k,x;
    bool b;
    str s;
    cin >> n;
    cin >> k;
    vll v;
    ll l = 0;
    ll prev = -1;
    rep(i,0,n){
        cin >> x;
        if(x != prev && i != 0){
            v.push_back(l);
            l = 0;
        }
        l++;

        prev = x;
    }
    if(l != 0){
        v.push_back(l);
    }
    

    sort(all(v));
    ll idx = 0;
    ll sum = n; // total deleted
    ll nArrays = 0;
    //printstruct(v);
    ll prevIdx = -1;
    rep(i,0,v[sz(v)-1]){
       // cout << sum << "," << idx << " ";

        
        while(idx < sz(v) && v[idx] == i){
            idx++;
        }
        if(k >= sum && (((k-sum) % (sz(v) - idx)) == 0) && prevIdx != idx){
            //cout << k-sum << "," << (idx) << " ";
            //cout << i << " ";
            nArrays++;
            prevIdx = idx;
        }
        sum -= sz(v)-idx;
    }
    cout << nArrays;
    

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
    return 0;
}
