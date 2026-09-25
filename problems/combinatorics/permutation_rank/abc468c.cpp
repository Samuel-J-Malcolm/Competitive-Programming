/*
Link: https://atcoder.jp/contests/abc468/tasks/abc468_c
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
#include <bit> // Required for bit operations

#define NO cout << ("No"); return;
#define YES cout << ("Yes"); return;

#ifdef LOCAL
#define dbg(x) cout << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif


int bw(unsigned long long x) {
    return x == 0 ? 0 : 64 - __builtin_clzll(x);
}

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

#ifdef LOCAL
#define ps(x) printstruct(x) << "\n"
#else
#define ps(x)
#endif

template<typename... Args>
void input(Args&... args) {
    ((cin >> args), ...);
}

template<typename... Args>
void out(const Args&... args) {
    ((cout << args), ...);
}

void solve(){
    vector<ll> factorials = {1,1,2,6,24,120,720,5040,40320,362880,3628800};
    ll x,y,n;
    input(n);
    vll v(n);
    vll v1(n);
    rep(i,0,n){
        input(v[i]);
    }
    rep(i,0,n){
        input(v1[i]);
    }
    unordered_set<int> a_set = {};
    rep(i,1,n+1){
        a_set.insert(i);
    }
    unordered_set<int> c_set = a_set;
    x = 0;
    rep(i,0,n){
        c_set.erase(v[i]);
        for(int i1: c_set){
            if(i1 < v[i]){
                x += factorials[n-i-1];
            }
        }
    }
    c_set = a_set;
    y = 0;
    rep(i,0,n){
        c_set.erase(v1[i]);
        for(int i1: c_set){
            if(i1 < v1[i]){
                y += factorials[n-i-1];
            }
        }
    }
    out(max(y-x-1,0LL));
    

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    //cin >> t;
    while (t--){
        solve();
        out("\n");
    }
    return 0;
}
