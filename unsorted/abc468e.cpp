/*
Link: https://atcoder.jp/contests/abc468/tasks/abc468_e
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
const ll  MOD = 998244353;

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

ll power(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        //exp & 1 means that 
        if (exp & 1) result = result * base % mod;
        base = (base * base) % mod; //
        exp >>= 1; //divides by 2
    }
    return result;
}

ll modinvprime(ll a, ll mod) { return power(a, mod - 2, mod); } // mod must be prime


void solve(){
    ll m,n,k,x,in;
    bool b;
    str s;
    input(n);
    vll v(n);
    vll inv1(n);
    rep(i,1,n+1){
        inv1[i-1] = modinvprime(i,MOD);
    }
    ll t = 0;
    ll f = 0;
    rep(i,0,n){
        input(v[i]);
    }
    f = 0;
    vll prefsum(n);
    rep(l,1,n+1){
        m = inv1[l-1];
        m %= MOD;
        f += m;
        f %= MOD;
        prefsum[l-1] = f;
    }
    rep(i,0,n){
        t += f*v[i] % MOD;
        if(i != n-1){
            f += prefsum[n-i-1];
            f %= MOD;
            f -= prefsum[i+1]-MOD;
            f %= MOD;
        }
    }
    out(t);
    

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
